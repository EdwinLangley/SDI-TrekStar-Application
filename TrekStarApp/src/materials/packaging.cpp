#include "packaging.h"

string Packaging::getMaterial() const
{
    return material;
}

void Packaging::setMaterial(const string &value)
{
    material = value;
}

unsigned int Packaging::getHeight() const
{
    return height;
}

void Packaging::setHeight(unsigned int value)
{
    height = value;
}

unsigned int Packaging::getWidth() const
{
    return width;
}

void Packaging::setWidth(unsigned int value)
{
    width = value;
}

unsigned int Packaging::getDepth() const
{
    return depth;
}

void Packaging::setDepth(unsigned int value)
{
    depth = value;
}

Packaging::Packaging()
{

}
