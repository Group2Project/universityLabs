int GamilC(int k){

int q1 = 0;

for(int i=0;i<n && !q1;i++){

        if(city[i].checkCopy(path[k-1]+1) || city[path[k-1]].checkCopy(i+1)){//Здесь проверяется связаны ли узлы

            if(k==n && i==point)
                   q1=1;
            else if(c[i]==-1){
                   c[i] = k;
                   path[k] = i;
                   q1 = GamilC(k+1);

                   if(!q1)
                        c[i] = -1;
                 }
             else
                continue;

        }


}
 return q1;
}