#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/gfx/seadColor.h>
#include <sead/math/seadVector.h>

namespace sead {
namespace PrimitiveRendererUtil
{
class Vertex
{
public:
    Vertex(const Vector3f& pos, const Vector2f& uv, const Color4f& color)
        : pos(pos), uv(uv), color(color)
    {
    }

    Vector3f pos;
    Vector2f uv;
    Color4f color;
};

void setQuadVertex(Vertex* vtx, u16* idx);
void setLineVertex(Vertex* vtx, u16* idx);
void setCubeVertex(Vertex* vtx, u16* idx);
void setWireCubeVertex(Vertex* vtx, u16* idx);
void setSphereVertex(Vertex* vtx, u16* idx, s32 x, s32 y);
void setDiskVertex(Vertex* vtx, u16* idx, s32 div);
void setCylinderVertex(Vertex* vtx, u16* idx, s32 div);

}  // namespace PrimitiveRendererUtil
}  // namespace sead


