#ifndef __LINE2D_H__
#define __LINE2D_H__

class Vector2D;
class Matrix2D;

class Line2D
{
  private:
    // ax + by = c
    double m_a;
    double m_b;
    double m_c;

  public:
    double a() const
    {
      return m_a;
    }

    double b() const
    {
      return m_b;
    }

    double c() const
    {
      return m_c;
    }

    Line2D() : m_a(1.0), m_b(1.0), m_c(0.0) { }
    Line2D( const double aa, const double bb, const double cc)
    {
      m_a = aa;
      m_b = bb;
      m_c = cc;
    }
/*
    Line2D( const Vector2D p1, const Vector2D p2 )
    {
      assign(p1, p2);
    }
*/
    Line2D assign(const Vector2D p1, const Vector2D p2)
    {
      m_a = -(p2.y - p1.y);
      m_b = p2.x - p1.x;
      m_c = m_a * p1.x - m_b * p1.y;

      return *this;
    }

    bool isParallel(const Line2D line) const
    {
      Matrix2D matrixA(m_a, m_b, line.a(), line.b());
      if(matrixA.det() == 0) return true;
      else                   return false;
    }

    Vector2D intersection(const Line2D line) const
    {
      Matrix2D matrixA(m_a, m_b, line.a(), line.b());
      Matrix2D inv_A = matrixA.inv();
      Vector2D vectorB(m_c, line.c());
      
      return ( inv_A.product(vectorB) );
    }

};

#endif //__LINE2D_H__
