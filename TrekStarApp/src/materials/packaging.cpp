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

string Packaging::getPackaging()
{
    string packaging;
    packaging.append(this->material);
    packaging.append(FIRSTLEVELDELIMSTRNG);
    packaging.append(to_string(this->height));
    packaging.append(FIRSTLEVELDELIMSTRNG);
    packaging.append(to_string(this->width));
    packaging.append(FIRSTLEVELDELIMSTRNG);
    packaging.append(to_string(this->depth));
    return packaging;
}

Packaging::Packaging()
{

}

Packaging::Packaging(string material, unsigned int height, unsigned int width, unsigned int depth)
{

}
