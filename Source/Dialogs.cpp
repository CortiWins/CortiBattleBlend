namespace Dialogs
{
// Shows a number in a MessageBox.
void Mbox( int value, std::string caption )
{
    std::stringstream strea;
    strea.clear();
    strea << value;
    MessageBox ( NULL, strea.str().c_str(),  caption.c_str(),  MB_OK | MB_ICONWARNING );
}

// Shows a text in a MessageBox.
void Mbox ( std::string value, std::string caption )
{
    MessageBox ( NULL, value.c_str(),  caption.c_str(),  MB_OK | MB_ICONWARNING );
}

}
