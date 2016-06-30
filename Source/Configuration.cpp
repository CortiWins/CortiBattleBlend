//! Enthält Configuration
std::map<std::string, std::string> configMap;

bool configured = false;

int SwitchBattle = 0;
int SwitchMap = 0;

int VarRed = 0;
int VarGreen = 0;
int VarBlue= 0;

int VarPictureId = 0;

void LoadConfig(char *pluginName)
{
    int configCount = 0;

    // We load the configuration from the DynRPG.ini file here
    configMap = RPG::loadConfiguration(pluginName);

    if(configMap.count("Switch_DrawScreentoneBattle"))
    {
        int value = atoi(configMap["Switch_DrawScreentoneBattle"].c_str());
        if(value>0)
        {
            SwitchBattle = value;
            configCount++;
        }
    }

    if(configMap.count("Switch_DrawScreentoneMap"))
    {
        int value = atoi(configMap["Switch_DrawScreentoneMap"].c_str());
        if(value>0)
        {
            SwitchMap = value;
            configCount++;
        }
    }

    if(configMap.count("Variable_RedChannel"))
    {
        int value = atoi(configMap["Variable_RedChannel"].c_str());
        if(value>0)
        {
            VarRed = value;
            configCount++;
        }
    }

    if(configMap.count("Variable_GreenChannel"))
    {
        int value = atoi(configMap["Variable_GreenChannel"].c_str());
        if(value>0)
        {
            VarGreen = value;
            configCount++;
        }
    }

    if(configMap.count("Variable_BlueChannel"))
    {
        int value = atoi(configMap["Variable_BlueChannel"].c_str());
        if(value>0)
        {
            VarBlue = value;
            configCount++;
        }
    }

    if(configMap.count("VariablePictureId"))
    {
        int value = atoi(configMap["VariablePictureId"].c_str());
        if(value>0)
        {
            VarPictureId = value;
            configCount++;
        }
    }

    if(configCount<6)
    {
        std::stringstream strea;
        strea.clear();
        strea << "Configuration Data:" << std::endl;
        strea << "Switch ID Battle: " << SwitchBattle<< std::endl;
        strea << "Switch ID Map  : " << SwitchMap<< std::endl;
        strea << "Variable Picture ID: " << VarPictureId<< std::endl;
        strea << "Variable ID Red: " << VarRed<< std::endl;
        strea << "Variable ID Green: " << VarGreen<< std::endl;
        strea << "Variable ID Blue: " << VarBlue<< std::endl << std::endl;
        strea << "Make sure all settings are set to switches and variables with IDs greater 0. See Readme for details." << std::endl;
        Dialogs::Mbox(strea.str(),"CortiBattleBlend");
    }
    else
    {
        configured = true;
    }
}
