#include <render/vertex.hpp>

// Vertex default constructor.
cosmodon::vertex::vertex()
: cosmodon::vector(0, 0, 0),
  cosmodon::color(cosmodon::black),
  w(1)
{

}

// Vertex constructor, without w component.
cosmodon::vertex::vertex(cosmodon::number init_x, cosmodon::number init_y, cosmodon::number init_z,
                         cosmodon::color color)
: cosmodon::vector(init_x, init_y, init_z),
  cosmodon::color(color),
  w(1)
{

}

// Vertex constructor, with w component.
cosmodon::vertex::vertex(cosmodon::number init_x, cosmodon::number init_y, cosmodon::number init_z,
                         cosmodon::number init_w, cosmodon::color color)
: cosmodon::vector(init_x, init_y, init_z),
  cosmodon::color(color),
  w(init_w)
{

}

// Vertex constructor, from vector.
cosmodon::vertex::vertex(const cosmodon::vector &other, cosmodon::color c)
: cosmodon::vector(other.x, other.y, other.z),
  cosmodon::color(c),
  w(1)
{

}

// Vertex copy constructor.
cosmodon::vertex::vertex(const cosmodon::vertex &copy)
: cosmodon::vector(copy.x, copy.y, copy.z),
  cosmodon::color(copy.r, copy.g, copy.b, copy.a),
  w(copy.w)
{

}

// Assignment to color operator.
cosmodon::vertex& cosmodon::vertex::operator=(const cosmodon::color value)
{
    r = value.r;
    g = value.g;
    b = value.b;
    a = value.a;
    return *this;
}

// Vertex to string.
cosmodon::vertex::operator std::string() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

// Data access operator.
cosmodon::vertex& cosmodon::vertices::operator [](const uint32_t index)
{
    return m_vertices[index];
}

// Const data access operator.
const cosmodon::vertex& cosmodon::vertices::operator [](const uint32_t index) const
{
    return m_vertices[index];
}

// Vertex and matrix multiplication.
cosmodon::vertex operator*(const cosmodon::matrix &lhs, const cosmodon::vertex &rhs)
{
    cosmodon::vertex result;

    result.x = (lhs[0][0] * rhs.x) + (lhs[0][1] * rhs.y) + (lhs[0][2] * rhs.z) + (lhs[0][3] * rhs.w);
    result.y = (lhs[1][0] * rhs.x) + (lhs[1][1] * rhs.y) + (lhs[1][2] * rhs.z) + (lhs[1][3] * rhs.w);
    result.z = (lhs[2][0] * rhs.x) + (lhs[2][1] * rhs.y) + (lhs[2][2] * rhs.z) + (lhs[2][3] * rhs.w);
    result.w = (lhs[3][0] * rhs.x) + (lhs[3][1] * rhs.y) + (lhs[3][2] * rhs.z) + (lhs[3][3] * rhs.w);

    return result;
}

// Vertex and matrix multiplcation, reverse order.
cosmodon::vertex operator*(const cosmodon::vertex &lhs, const cosmodon::matrix &rhs)
{
    return rhs * lhs;
}
