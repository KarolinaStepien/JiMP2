//
// Created by Admin on 2017-03-28.
//

#include "SimpleTemplateEngine.h"

using nets::View;

int main(){
    /*View view{"Hello {{name}}! How are you today? My name is {{program}}!"};
    unordered_map <string,string> karola = {{"name", "Xavier"}, {"program", "Borg"}};
    cout << view.Render(karola);*/
    /*View view{"Hello {{name}}! How are you today? My name is {{program}}!"};
    cout << view.Render({{"name","Xavier"}, {"program", "Borg"}});*/
    View view{"Test {{test}} missing:{{missing}}:missing"};
    cout << view.Render({{"test", "replacement"}});
    return 0;
}