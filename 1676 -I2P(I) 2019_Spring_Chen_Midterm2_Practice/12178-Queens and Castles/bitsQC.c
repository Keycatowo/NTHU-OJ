//
//
//
//void solve2(int row,int col,int QJ,int QL,int CJ,int CL,int Qs,int Cs){
//    if(Cs>0){
//        int able = ((1<<E)-1) & (col|QJ|QL);
//        while(able){
//            int pos = able & -able;
//            able ^= pos;
//            if(row == E-1) sum++;
//            else solve2(row+1,col|pos,QJ,QL,(CJ|pos)>>1,(CL|pos)<<1,Qs,Cs-1);
//        }
//    }
//    if(Qs>0){
//        int able = ((1<<E)-1) & (col|QJ|QL|CJ|CL);
//        while(able){
//            int pos = able & -able;
//            able ^= pos;
//            if(row == E-1) sum++;
//            else solve2(row+1,col|pos,(QJ|pos)>>1,(QL|pos)<<1,CJ,CL,Qs,Cs-1);
//        }
//    }
//
//
//
//
//}
