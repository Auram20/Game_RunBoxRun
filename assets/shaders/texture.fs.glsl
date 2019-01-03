# version 300 es

precision mediump float;
// Sorties du shader

#define MAX_TEXTURE 10

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet


out vec3 fFragColor;

//uniform vec3 uColor;
uniform sampler2D uTexture[MAX_TEXTURE];
uniform uint uTextureSize;

void main() {
  fFragColor = vec3(0, 0, 0);
  for(uint i = 0u; i < uTextureSize; ++i) {
    fFragColor += texture(uTexture[i], vTexCoords).xyz;
  }
 }
