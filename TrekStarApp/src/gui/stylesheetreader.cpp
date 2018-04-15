#include "gui.h"

QStringList styleVariables;

// Opens txt file which stores variables used in style sheet, creates list
// of each variable and corresponding value
void readVariables(){

    QFile styleVariablesFile(":/style/styleVariables.txt");
    styleVariablesFile.open(QFile::ReadOnly);
    QString styleVariablesString = styleVariablesFile.readAll();
    styleVariablesFile.close();

    QStringList buffer = styleVariablesString.split(";",QString::SkipEmptyParts);

    for(int i = 0; i < buffer.size(); i++){
        styleVariables.append(buffer[i].split("=",QString::SkipEmptyParts));
    }

    for(int j = 0; j < styleVariables.size(); ++j){
        styleVariables[j] = styleVariables[j].trimmed();
    }

    styleVariables.pop_back();

}

// Opens QSS file and stores files content in QString
QString readStyleSheet(QString filePath){

    QFile windowStyleSheet(filePath);
    windowStyleSheet.open(QFile::ReadOnly);
    QString styleCode = windowStyleSheet.readAll();
    windowStyleSheet.close();

    // Replaces each instance of variable used with the corresponding value
    for(int i = 0; i < styleVariables.size() - 1; i = i + 2){
        styleCode.replace(styleVariables[i], styleVariables[i+1]);
    }

    return styleCode;

}
