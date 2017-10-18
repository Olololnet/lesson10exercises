#ifndef CPOINT_H
#define CPOINT_H

class CPoint
{
public:
    CPoint();
    CPoint(double dX, double dY);

    void SetCoordinates(const double& dX, const double& dY);
    void ShowCoordinates() const;

    const double& GetX() const;
    const double& GetY() const;

    void SetX(const double& dX);
    void SetY(const double& dY);

private:
    double m_dX;
    double m_dY;
};

#endif
