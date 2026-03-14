#include<iostream>
#include<memory>
#include<string>
using namespace std;

// Texture class
class Texture{
    string name;
    public:
    Texture(const string &name){
        this->name = name;
        cout<<"[Texture] Loading "<<name<<endl;
    }
    ~Texture(){
        cout<<"[Texture] Unloading "<<this->name<<endl;
    }
    void render() const { 
        std::cout << "[Texture] Rendering with: " << name << std::endl;
    }
};

// Shader class
class Shader{
    string name;
    public:
    Shader(const string &name){
        this->name = name;
      cout<<"[Shader] Compiling: " + name<<endl;
    }

    ~Shader(){
      cout<<"[Shader] Deleting: " + this->name<<endl;
    }

    void apply() const { 
        std::cout << "[Shader] Applying: " << name << std::endl; 
    }
};

class GameObject{
    private:
        unique_ptr<Texture>Text;
        shared_ptr<Shader>Shad;
    public:
        GameObject(const string& textureName, shared_ptr<Shader>sharedShader){
            Text = make_unique<Texture>(textureName);
            Shad = sharedShader;
            cout<<"[GameObject] Created"<<endl;
        }

        ~GameObject(){
            cout<<"[GameObject] Destroyed"<<endl;
        }

        void draw(){
            Text->render();
            Shad->apply();
        }
        void changeTexture(const std::string& newTextureName){
            Text = make_unique<Texture>(newTextureName);
        }
};

int main(){
    cout << "--- Creating Shaders ---" << endl;
    shared_ptr<Shader>defaultLightingShader = make_shared<Shader>("BasicLightingShader");
    shared_ptr<Shader>postFxShader  = make_shared<Shader>("GrayscaleFilterShader");

    cout << "\n--- Creating GameObjects ---" << endl;
    GameObject player("PlayerTexture", defaultLightingShader); 
    GameObject enemy("EnemyTexture", defaultLightingShader);
    GameObject background("BackgroundTexture", postFxShader);

    cout << "\n--- Drawing GameObjects ---" << endl;
    player.draw(); 
    enemy.draw();
    background.draw();

    cout << "\n--- Changing Player Texture ---" << endl;
    player.changeTexture("PlayerDamagedTexture");
    player.draw();

    std::cout << "\n--- Demonstrate Scope-based Cleanup ---" << std::endl;
{
    std::cout << "Entering a local scope..." << std::endl;
    GameObject temporaryProp("TempPropTexture", defaultLightingShader); // Creates a GameObject`
    temporaryProp.draw();
    std::cout << "Exiting local scope..." << std::endl;
}
cout << "\n--- End of main ---" << endl;
return 0;

}