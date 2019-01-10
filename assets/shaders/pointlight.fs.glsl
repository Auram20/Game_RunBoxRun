# version 330 core

#define MAX_SIZE 12
#define MAX_LIGHT 10

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;

uniform vec3 uK[MAX_SIZE];
uniform float uShininess;

uniform vec3 uLightPos_vs[MAX_LIGHT];
uniform vec3 uLightIntensity[MAX_LIGHT];
uniform int uLightType[MAX_LIGHT];

uniform sampler2D uTexture[MAX_SIZE];

float dotN(vec3 v1, vec3 v2) {
    float d = dot(v1, v2);
    return (d < 0) ? 0 : d;
}

vec3 blinnPhongPoint() {
    vec3 diffuse = uKd * dotN(normalize(uLightPos_vs - vPosition_vs), normalize(vNormal_vs));
    vec3 glossy = uKs * pow(dotN(((normalize(uLightPos_vs) + normalize(-vPosition_vs)) / 2.f), normalize(vNormal_vs)), uShininess);
    float d = distance(uLightPos_vs, vPosition_vs);
    vec3 color = (uLightIntensity / (d * d)) * (diffuse + glossy);
    return color;
}

vec3 blinnPhongDirectional() {
    vec3 diffuse = uKd * dotN(normalize(uLightDir_vs), normalize(vNormal_vs));
    vec3 glossy = uKs * pow(dotN(((normalize(uLightDir_vs) + normalize(-vPosition_vs)) / 2.f), normalize(vNormal_vs)), uShininess);
    vec3 color = uLightIntensity * (diffuse + glossy);
    return color;
}

void main() {
    vec3 color = mix(color[1], texture(uTexture[1], vTexCoords));
    fFragColor = color *  blinnPhong();
}
