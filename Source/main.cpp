#include <DynRPG/DynRPG.h>

#include <iostream>
#include <fstream>
#include <sstream> // For std::stringstream
#include <algorithm>

#include "Dialogs.cpp"
#include "Configuration.cpp"
#include "Screentone.cpp"

// Contains if the Screentone was already changed in this frame.
bool doneDrawn = false;

// Handler called on startup
bool onStartup(char *pluginName)
{
    LoadConfig(pluginName);
    return true;
}



// Zeichnet das Fenster für die Handlungsauswahl
bool onDrawBattleActionWindow ( int * x, int * y, int selection, bool selActive, bool isVisible)
{
    if(configured > 0 && !doneDrawn && RPG::switches[SwitchBattle])
    {
        Tone();
        doneDrawn = true;
    }

    return true;
}

// Called when a picture is going to be drawn.
bool onDrawPicture (RPG::Picture *picture)
{
    if(configured && !doneDrawn && RPG::system->scene == RPG::SCENE_MAP && RPG::switches[SwitchMap])
    {
        int pictureId = RPG::variables[VarPictureId];
        if(pictureId > 0 && picture->id >= pictureId)
        {
             Tone();
            doneDrawn = true;
        }
    }

    return true;
}

// Called on every frame after all other drawing callbacks.
void onFrame ( RPG::Scene scene )
{
    if(configured && !doneDrawn && RPG::system->scene == RPG::SCENE_MAP && RPG::switches[SwitchMap])
    {
        if(RPG::variables[VarPictureId] == 0)
        {
            Tone();
            doneDrawn = true;
        }
    }

    doneDrawn = false;
}
