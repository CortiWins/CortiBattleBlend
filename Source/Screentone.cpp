
uint16_t src;
const unsigned char pixCon31 = 31;
const unsigned char pixCon63 = 63;

//! Zeichnet Bilddaten im angewählten Blendmodus
inline void Tone ()
{
    // Number of bytes you have to add to a pixel address to get the address of the pixel in the same column of the next pixel row
    int swid = RPG::screen->canvas->lineSize / 2;

    // Pointer auf Pixeldaten beginnend bei Zeile 0
    uint16_t* scanline = RPG::screen->canvas->getScanline ( 0 );

    int sPtr = 0;
    for ( int i = 0; i < 240; ++i )
    {
        for ( int j = 0; j < 320; ++j )
        {
            src = scanline[sPtr];

            unsigned char rPix = ( src >> 11 ) ;
            unsigned char gPix = ( src & 0x07E0 ) >> 5;
            unsigned char bPix = ( src & 0x001F ) ;

            rPix = rPix * RPG::variables[VarRed] / 100;
            gPix = gPix * RPG::variables[VarGreen] / 100;
            bPix = bPix * RPG::variables[VarBlue] / 100;

            rPix = std::min ( pixCon31, rPix);
            gPix = std::min ( pixCon63, gPix );
            bPix = std::min ( pixCon31, bPix );

            scanline[sPtr] =  ( rPix << 11 ) | ( gPix << 5 ) | bPix ;
            ++sPtr;
        }

        sPtr += swid - 320;
    }
}
