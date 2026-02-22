#include <gui/containers/SVGContainer.hpp>

SVGContainer::SVGContainer() :
    rotationCenterX(0),
    rotationCenterY(0),
    touchAreaOffset(0)
{

}

void SVGContainer::initialize()
{
    SVGContainerBase::initialize();
    setTouchable(true);

    // Set the initial rotation center to the middle of the container
    rotationCenterX = getWidth() / 2;
    rotationCenterY = getHeight() / 2;
}

int16_t SVGContainer::getRotationCenterX()
{
    return rotationCenterX;
}

int16_t SVGContainer::getRotationCenterY()
{
    return rotationCenterY;
}

void SVGContainer::setTouchAreaOffset(int16_t offset)
{
    touchAreaOffset = offset;
}

void SVGContainer::handleDragEvent(const DragEvent& event)
{
    updateRotationCenterValues(event.getNewX(), event.getNewY());

    // Notify the screen that a new RotationCenter is available
    emitRotationCenterUpdatedCallback();
}

void SVGContainer::handleClickEvent(const ClickEvent& event)
{
    updateRotationCenterValues(event.getX(), event.getY());

    // Notify the screen that a new RotationCenter is available
    emitRotationCenterUpdatedCallback();
}

void SVGContainer::updateRotationCenterValues(int16_t x, int16_t y)
{
    rotationCenterX = x;
    rotationCenterY = y;

    // Make sure the rotation center is within the area of this
    // container. Take into account the width/height of the
    // RotationCenterMarker (touchAreaOffset)
    if (rotationCenterX < touchAreaOffset / 2)
    {
        rotationCenterX = touchAreaOffset / 2;
    }
    else if (rotationCenterX > getWidth() - touchAreaOffset)
    {
        rotationCenterX = getWidth() - touchAreaOffset;
    }

    if (rotationCenterY < touchAreaOffset / 2)
    {
        rotationCenterY = touchAreaOffset / 2;
    }
    else if (rotationCenterY > getHeight() - touchAreaOffset)
    {
        rotationCenterY = getHeight() - touchAreaOffset;
    }
}
