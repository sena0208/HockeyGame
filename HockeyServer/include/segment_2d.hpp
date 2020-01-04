#ifndef __SEGMENT2D_H__
#define __SEGMENT2D_H__

class Matrix2D;
class Line2D;
class Vector2D;

class Segment2D {
  private:
    Vector2D m_origin;
    Vector2D m_terminal;

  public:
    Segment2D()
    {
      m_origin.x = 0.0;
      m_origin.y = 0.0;

      m_terminal.x = 0.0;
      m_terminal.y = 0.0;
    }

    Segment2D(const Vector2D origin, const Vector2D terminal) : m_origin( origin ), m_terminal( terminal )
  { }
    Segment2D( const double origin_x,
               const double origin_y,
               const double terminal_x,
               const double terminal_y )
      : m_origin( origin_x, origin_y ), m_terminal( terminal_x, terminal_y )
    { }

    Segment2D assign( const Vector2D origin, const Vector2D terminal )
    {
      m_origin = origin;
      m_terminal = terminal;
      return *this;
    }

    Vector2D origin() const
    {
      return m_origin;
    }

    Vector2D terminal() const
    {
      return m_terminal;
    }
/*
    Line2D line() const
    {
      return Line2D( origin(), terminal() );
    }
*/
    double length() const
    {
      return origin().dist( terminal() );
    }

    bool hasIntersection(Segment2D other)
    {
      /* write here */
      return true;
    }

    Vector2D intersection(Segment2D othere)
    {
      Vector2D vec;
      /* write here */
      return vec;
    }

};

#endif //__SEGMENT2D_H__
