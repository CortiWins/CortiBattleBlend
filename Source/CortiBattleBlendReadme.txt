CortiBattleBlend DynRPG PlugIn V0.2 for RPG Maker 2003 with DynRPG v0.20 or higher

https://github.com/CortiWins/CortiBattleBlend
*******************************************************************
*                     Author
*******************************************************************
Corti: Plugin 13.09.2013 for Innocentias Dark Sword.
Kazesui: The code for adressing each pixel is taken from his PictureBlend plugin.

*******************************************************************
*                     Versions
*******************************************************************
0.1  ( 13.09.2013 ) First version. Sets Screentone in battle.
02. ( 30.06.2016 ) Allows to set screentone on maps.

*******************************************************************
*                     The purpose of this plugin
*******************************************************************
 The RM2k3s screentone function can not set the color of heroes in battle and pictures and animations on the map.
 The plugin complements that.

 In battle it can set the screentone of everything that is drawn before the menu elements.
On the map it can set the screentone of everything on screen, or if you want, it can do so before any given picture is drawn.
That way, you can set the screentone of pictures that are part of the map while not changing the color of pictures that are part of menus and textboxes.

BattleAnimations on the map are drawn above all pictures. So if you want to set the screentone of animations but not the screentone of everything including all pictures, you can use a progam called HyperPatcher2 to change the drawing order to animations first.
You can get it here: http://cherrytree.at/cms/lang/de/download/?did=10

The plugin changes the color channels of each pixel by multiplication with a given value.

*******************************************************************
*                     Using the plugin
*******************************************************************
Switch_DrawScreentoneBattle : This switch determines if screentone is active in battle
Switch_DrawScreentoneMap : This switch determines if screentone is active on the map
VariablePictureId : This variable can contain a picture ID. If for exaple the given ID is 18, the screentone will be applied just before picture 18. 1 to 17 will be colored while 18 and later are not affected. If the variable is zero, the complete screen is colored.

The following three contains multiplicators for each color channel.
Variable_RedChannel
Variable_GreenChannel
Variable_BlueChannel

[CortiBattleBlend]
Switch_DrawScreentoneBattle=1
Switch_DrawScreentoneMap=2
VariablePictureId = 14
Variable_RedChannel = 15
Variable_GreenChannel = 16
Variable_BlueChannel = 17

*******************************************************************
*                     Problems & Feedback
*******************************************************************
Write me in the forums
( German ) http://www.multimediaxis.de/members/4806-Corti
( English ) https://rpgmaker.net/users/Corti/

