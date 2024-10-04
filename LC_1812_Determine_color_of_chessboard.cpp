class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if((coordinates[0]=='a'||coordinates[0]=='c'||coordinates[0]=='e'||coordinates[0]=='g') && (coordinates[1]=='1'||coordinates[1]=='3'||coordinates[1]=='5'||coordinates[1]=='7')){
            return false;
        }
        if((coordinates[0]=='b'||coordinates[0]=='d'||coordinates[0]=='f'||coordinates[0]=='h') && (coordinates[1]=='2'||coordinates[1]=='4'||coordinates[1]=='6'||coordinates[1]=='8')){
            return false;
        }
        return true;
        
    }
};