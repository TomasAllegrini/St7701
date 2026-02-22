#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // Inform the SVGContainer of the size of the rotationCenterMarker
    // so that it will not place it outside the SVG area
    svgContainer.setTouchAreaOffset(rotationCenterMarker.getWidth());

    // Make sure the rotation center is set from the beginning
    updateRotationCenter();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateRotationCenter()
{
    // Place the marker where the SVG contanier was touched
    rotationCenterMarker.moveTo(svgImage1.getX() + svgContainer.getRotationCenterX() - (rotationCenterMarker.getWidth() / 2),
                                svgImage1.getY() + svgContainer.getRotationCenterY() - (rotationCenterMarker.getHeight() / 2));

    // Set the new rotation center of the SVG
    svgImage1.setRotationCenter(svgContainer.getRotationCenterX(), svgContainer.getRotationCenterY());

    //Reset the scale and rotation  of the SVG
    svgImage1.setScale(1.f);
    svgImage1.setRotation(0.f);

    // Redraw the SVG
    svgImage1.invalidate();
}
