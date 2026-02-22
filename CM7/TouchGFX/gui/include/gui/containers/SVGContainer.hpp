#ifndef SVGCONTAINER_HPP
#define SVGCONTAINER_HPP

#include <gui_generated/containers/SVGContainerBase.hpp>


// Container for handling click and drag of the rotation center
// The container emits an event when there is a new value
// for the rotation center, which will be handled by the
// Screen1View. This event is defined in the TouchGFX Designer
// as a trigger for the custom container.
class SVGContainer : public SVGContainerBase
{
public:
    SVGContainer();
    virtual ~SVGContainer() {}

    virtual void initialize();
    void setTouchAreaOffset(int16_t offset);

    int16_t getRotationCenterX();
    int16_t getRotationCenterY();

protected:
    int16_t rotationCenterX;
    int16_t rotationCenterY;
    int16_t touchAreaOffset;

    void handleDragEvent(const DragEvent& event);
    void handleClickEvent(const ClickEvent& event);

    void updateRotationCenterValues(int16_t x, int16_t y);

};

#endif // SVGCONTAINER_HPP
