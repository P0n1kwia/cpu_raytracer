#pragma once
#include "model.hpp"

bool model::load_model_world(world& w)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filepath.c_str())) {
        return false;
    }

    for (const auto& shape : shapes) {
        size_t index_offset = 0;
        for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
            int fv = shape.mesh.num_face_vertices[f];
            if (fv != 3) { index_offset += fv; continue; } // skip non-triangle

            // positions
            tinyobj::index_t idx0 = shape.mesh.indices[index_offset + 0];
            tinyobj::index_t idx1 = shape.mesh.indices[index_offset + 1];
            tinyobj::index_t idx2 = shape.mesh.indices[index_offset + 2];

            vec3 v0 = get_vertex(attrib, idx0.vertex_index);
            vec3 v1 = get_vertex(attrib, idx1.vertex_index);
            vec3 v2 = get_vertex(attrib, idx2.vertex_index);

            // normals (if present)
            if (!attrib.normals.empty()) {
                vec3 n0 = get_normal(attrib, idx0.normal_index);
                vec3 n1 = get_normal(attrib, idx1.normal_index);
                vec3 n2 = get_normal(attrib, idx2.normal_index);
                w.add(std::make_shared<triangle>(v0, v1, v2, n0, n1, n2));
            }
            else {
                w.add(std::make_shared<triangle>(v0, v1, v2));
            }

            index_offset += fv;
        }
    }
    return true;
}


vec3 model::get_vertex(const tinyobj::attrib_t& attrib, int ind)
{
    return vec3(
        attrib.vertices[3 * ind + 0],
        attrib.vertices[3 * ind + 1],
        attrib.vertices[3 * ind + 2]
    );
}

vec3 model::get_normal(const tinyobj::attrib_t& attrib, int ind)
{
    return vec3(
        attrib.normals[3*ind + 0],
        attrib.normals[3*ind + 1],
        attrib.normals[3*ind + 2]);
}
