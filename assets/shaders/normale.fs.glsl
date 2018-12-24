# version 300 es

precision mediump float;
// Sorties du shader

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet


out vec3 fFragColor;

//uniform vec3 uColor;
uniform sampler2D uTexture;

void main() {
  //fFragColor.rgb = vec3(1,0,0);

  fFragColor = normalize(vNormal_vs);
  //fFragColor = vec3(texture(uTexture, vTexCoords).xyz);
 }