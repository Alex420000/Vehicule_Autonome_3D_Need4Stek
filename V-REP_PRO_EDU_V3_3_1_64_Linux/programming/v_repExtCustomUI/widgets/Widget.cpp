#include "Widget.h"
#include "Button.h"
#include "Edit.h"
#include "HSlider.h"
#include "VSlider.h"
#include "Label.h"
#include "Checkbox.h"
#include "Radiobutton.h"
#include "Spinbox.h"
#include "Combobox.h"
#include "Group.h"
#include "Tabs.h"
#include "LayoutWidget.h"
#include "Image.h"

#include "XMLUtils.h"

#include "UIProxy.h"

std::map<QWidget *, Widget *> Widget::widgetByQWidget;

Widget::Widget(std::string widgetClass_)
    : qwidget(NULL),
      widgetClass(widgetClass_),
      proxy(NULL)
{
    // don't do this here because id is set by user:
    // Widget::widgets[id] = this;
}

Widget::~Widget()
{
#ifdef DEBUG
    std::cerr << str() << "::~Widget()" << std::endl;
#endif

    // this should be destroyed from the UI thread

    if(qwidget)
    {
#ifdef DEBUG
        std::cerr << str() << "::~Widget() - delete 'qwidget' member (deleteLater())" << std::endl;
#endif

        //qwidget->deleteLater();

        Widget::widgetByQWidget.erase(qwidget);
    }

    if(proxy)
    {
        proxy->widgets.erase(id);
    }
}

void Widget::setQWidget(QWidget *qwidget_)
{
    if(qwidget)
        throw std::runtime_error("qwidget has been already set");

    qwidget = qwidget_;
    Widget::widgetByQWidget[qwidget] = this;
}

void Widget::setProxy(Proxy *proxy_)
{
    proxy = proxy_;
    proxy->widgets[id] = this;
}

Widget * Widget::byId(int handle, int id)
{
    Proxy *proxy = Proxy::byHandle(handle);
    if(!proxy) return NULL;
    return proxy->getWidgetById(id);
}

Widget * Widget::byQWidget(QWidget *w)
{
    std::map<QWidget*, Widget*>::const_iterator it = Widget::widgetByQWidget.find(w);
    Widget *ret = it == Widget::widgetByQWidget.end() ? NULL : it->second;
    return ret;
}

Widget * Widget::parseAny(Widget *parent, std::map<int, Widget*>& widgets, tinyxml2::XMLElement *e)
{
    std::string tag(e->Value());
    if(tag == "button") return parse1<Button>(parent, widgets, e);
    if(tag == "edit") return parse1<Edit>(parent, widgets, e);
    if(tag == "hslider") return parse1<HSlider>(parent, widgets, e);
    if(tag == "vslider") return parse1<VSlider>(parent, widgets, e);
    if(tag == "label") return parse1<Label>(parent, widgets, e);
    if(tag == "checkbox") return parse1<Checkbox>(parent, widgets, e);
    if(tag == "radiobutton") return parse1<Radiobutton>(parent, widgets, e);
    if(tag == "spinbox") return parse1<Spinbox>(parent, widgets, e);
    if(tag == "combobox") return parse1<Combobox>(parent, widgets, e);
    if(tag == "group") return parse1<Group>(parent, widgets, e);
    if(tag == "tabs") return parse1<Tabs>(parent, widgets, e);
    if(tag == "stretch") return parse1<Stretch>(parent, widgets, e);
    if(tag == "image") return parse1<Image>(parent, widgets, e);

    std::stringstream ss;
    ss << "invalid element <" << tag << ">";
    throw std::range_error(ss.str());
}

void Widget::parse(Widget *parent, std::map<int, Widget*>& widgets, tinyxml2::XMLElement *e)
{
    if(e->Attribute("id"))
    {
        id = xmlutils::getAttrInt(e, "id", 0);
        // user defined IDs must be positive (see below)
        if(id <= 0)
        {
            throw std::range_error("id must be a positive integer");
        }
    }
    else
    {
        // automatically assigned IDs are negative, so we can distinguish them
        // in diagnostics
        static int nextId = -1;
        id = nextId--;
    }

    std::string tag(e->Value());
    if(tag != widgetClass)
    {
        std::stringstream ss;
        ss << "element must be <" << widgetClass << ">";
        throw std::range_error(ss.str());
    }
}

std::string Widget::str()
{
    std::stringstream ss;
    ss << "Widget[" << this << "," << widgetClass << "]";
    return ss.str();
}

