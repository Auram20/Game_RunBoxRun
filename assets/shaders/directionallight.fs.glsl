# version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

uniform sampler2D uTexture;

float dotN(vec3 v1, vec3 v2) {
    float d = dot(v1, v2);
    return (d < 0) ? 0 : d;
}

vec3 blinnPhong() {
    vec3 diffuse = uKd * dotN(normalize(uLightDir_vs), normalize(vNormal_vs));
    vec3 glossy = uKs * pow(dotN(((normalize(uLightDir_vs) + normalize(-vPosition_vs)) / 2.f), normalize(vNormal_vs)), uShininess);
    vec3 color = uLightIntensity * (diffuse + glossy);
    return color;
}

void main() {
    fFragColor = texture(uTexture, vTexCoords).xyz *  blinnPhong();
}