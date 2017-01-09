#version 330 core
out vec4 color;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct PhongLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadric;
};

uniform Material material;
uniform PhongLight light;
//uniform DirectionalLight light;
uniform vec3 viewPos;

void main()
{
    // Phong Light
    // Ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

    // Diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));  

    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    color = vec4(ambient + diffuse + specular, 1.0f);  

 //   //Directional Light
 //   // Ambient
 //   vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

    //// Diffuse 
 //   vec3 norm = normalize(Normal);
 //   vec3 lightDir = normalize(-light.direction);
 //   float diff = max(dot(norm, lightDir), 0.0);
 //   vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

    //// Specular
 //   vec3 viewDir = normalize(viewPos - FragPos);
 //   vec3 reflectDir = reflect(-lightDir, norm);
 //   float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
 //   vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

 //   color = vec4(ambient + diffuse + specular, 1.0f);
}