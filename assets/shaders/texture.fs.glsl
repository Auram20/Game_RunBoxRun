# version 300 es

precision mediump float;
// Sorties du shader

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet


out vec3 fFragColor;

//uniform vec3 uColor;
uniform sampler2D uTexture[10];

void main() {
  //fFragColor = vec3(1, 1, 1);
  //for(int i = 0; i < uTexture.length(); ++i) {
    fFragColor = texture2D(uTexture[0], vTexCoords).xyz;
  //}
 }
