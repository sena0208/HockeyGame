#ifndef __MATRIX2D_H__
#define __MATRIX2D_H__

class Vector2D;
class Line2D;

class Matrix2D
{
  private:
    double m_11;
    double m_12;
    double m_21;
    double m_22;

  public:
    Matrix2D();

    //Matrix2D() : m_11(1.0), m_12(0.0), m_21(0.0), m_22(1.0)
    //{ }

    Matrix2D(const double a, const double b, const double c, const double d)
    {
      m_11 = a;
      m_12 = b;
      m_21 = c;
      m_22 = d;
    }

    double det() const
    {
      return ( (m_11 * m_22) - (m_12 * m_21) );
    }

    Matrix2D inv() const
    {
      Matrix2D inv( (m_22 / det()), (-m_12 / det()), (-m_21 / det()), (m_11 / det()) );
      return inv;
    }

    Vector2D product(Vector2D vec){
      Vector2D ans;
      ans.x = (m_11 * vec.x) + (m_12 * vec.y);
      ans.y = (m_21 * vec.x) + (m_22 * vec.y);

      return vec;
    }

};

#endif //__MATRIX2D_H__
