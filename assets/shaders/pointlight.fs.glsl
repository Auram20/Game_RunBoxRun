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
uniform uint uLightSize;

uniform sampler2D uTexture[MAX_SIZE];

float dotN(vec3 v1, vec3 v2) {
    float d = dot(v1, v2);
    return (d < 0) ? 0 : d;
}

vec3 blinnPhongPoint(vec3 lightPos, vec3 lightIntensity) {
    vec3 diffuse = uK[1] * dotN(normalize(lightPos - vPosition_vs), normalize(vNormal_vs));
    vec3 glossy = uK[2] * pow(dotN(((normalize(lightPos) + normalize(-vPosition_vs)) / 2.f), normalize(vNormal_vs)), uShininess);
    float d = distance(lightPos, vPosition_vs);
    vec3 color = (lightIntensity / (d * d)) * (diffuse + glossy);
    return color;
}

vec3 blinnPhongDirectional(vec3 lightDir, vec3 lightIntensity) {
    vec3 diffuse = uK[1] * dotN(normalize(lightDir), normalize(vNormal_vs));
    vec3 glossy = uK[2] * pow(dotN(((normalize(lightDir) + normalize(-vPosition_vs)) / 2.f), normalize(vNormal_vs)), uShininess);
    vec3 color = lightIntensity * (diffuse + glossy);
    return color;
}

void main() {
    vec3 color = texture(uTexture[1], vTexCoords);
    fFragColor = color;
    for(uint i = 0; i < uLightSize; ++i) {
    if(uLightType[i] == 0) {
        fFragColor *= blinnPhongPoint(uLightPos_vs[i], uLightIntensity[i]);
    else if(uLightType[i] == 1) {
        fFragColor *= blinnPhongDirectional(uLightPos_vs[i], uLightIntensity[i]);
    }
}
