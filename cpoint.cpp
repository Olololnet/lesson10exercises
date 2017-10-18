#include "cpoint.h"
#include <iostream>

CPoint::CPoint()
:m_dX(0.)
,m_dY(0.)
{

}

CPoint::CPoint(double dX, double dY)
:m_dX(dX)
,m_dY(dY)
{

}

void CPoint::SetCoordinates(const double& dX, const double& dY)
{
    m_dX = dX;
    m_dY = dY;
}

void CPoint::ShowCoordinates() const
{
    std::cout << "Point x: " << m_dX << "; point y: " << m_dY << std::endl;
}

const double& CPoint::GetX() const
{
    return m_dX;
}

const double& CPoint::GetY() const
{
    return m_dY;
}

void CPoint::SetX(const double& dX)
{
    m_dX = dX;
}

void CPoint::SetY(const double& dY)
{
    m_dY = dY;
}
