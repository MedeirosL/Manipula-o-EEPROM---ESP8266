#include <EEPROM.h>
int flag=1,countn=0;
int n=4,s1=1,s2=1,s3=1,s4=0,s5=0,t1=0,t2=0,t3=0;
int sv1=0,sv2=0,sv3=0,sv4=0,sv5=0;
float tv1=15.14,tv2=0,tv3=0;
long epochnow=0;
int limit = 60*5+60;
int resetFlag=1;
int memorylimit=4000-50-16;
char vet[4096];

void setup() {
  Serial.begin(115200);
  EEPROM.begin(4096);
  delay(100);
  Serial.println();
  //////
  Serial.println();
  for(int i=0;i<4096;i++){
    EEPROM.write(i,0);
  }
  EEPROM.commit();
  /////
  //EEPROM.write(0, 7990>>8);
  //EEPROM.write(1, 7990);
  EEPROM.commit();
  //////
  //EscreveEEPROM(4,5,6,-9999,-9999,-9999,-9999,-9999,1300);
  EnviaDado(10,11,12,-9999,-9999,-9999,-9999,-9999,12000);
  Serial.println("\n\nContador:");
  for (int i = 0; i < 10; i++)
  {
    Serial.print(EEPROM.read(i));
    Serial.print("\t");
  }
  Serial.println("\nEpoch Salvo:");
  for (int i = 10; i < 30; i++)
  {
    Serial.print(EEPROM.read(i));
    Serial.print("\t");
    if((i-9)%4==0)
      Serial.println();
  }
  Serial.println("\nContador 1:");
  for (int i = 30; i < 40; i++)
  {
    Serial.print(EEPROM.read(i));
    Serial.print("\t");
  }
  Serial.println("\nContador 2:");
  for (int i = 40; i < 50; i++)
  {
    Serial.print(EEPROM.read(i));
    Serial.print("\t");
  }
  Serial.println("\nDados Armazenados:");
  for (int i = 50; i < 200; i++)
  {
    Serial.print(EEPROM.read(i));
    Serial.print("\t");
    if((i+1)%10==0){
      Serial.println();
     }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}


void EnviaDado(int sv1,int sv2,int sv3,int sv4,int sv5,int tv1,int tv2,int tv3,long epochnow){
    int count=1000,i=-2,n_data=0,n2_data,ns=3,data[8]={-9999,-9999,-9999,-9999,-9999,-9999,-9999,-9999},late=0,k=0,dataPos=0,y;
    long epochsvd=0;
    do{
        i+=2;
        count = int(EEPROM.read(0+i))*256 + int(EEPROM.read(1+i)); //count = vet[0+i]<<8+vet[1+i];
        Serial.println(count);
    }
    while(count>=8000);
    epochsvd=(((((EEPROM.read(10+2*i)*256) +EEPROM.read(11+2*i))*256) + EEPROM.read(12+2*i))*256) + EEPROM.read(13+2*i);   // (((((vet[10+2*i]<<8)+vet[11+2*i])<<8)+vet[12+2*i])<<8)+vet[13+2*i];
    n_data=int(EEPROM.read(30+i))*256 + int(EEPROM.read(31+i));  //vet[30+i]<<8+vet[31+i];
    n2_data=int(EEPROM.read(40+i))*256 + int(EEPROM.read(41+i)); //vet[40+i]<<8+vet[41+i];
    ns=s1+s2+s3+s4+s5+t1+t2+t3;
    while(n_data!=0){
        k=0;
        if (sv1!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (sv2!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (sv3!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (sv4!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (sv5!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (tv1!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (tv2!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        k++;
        if (tv3!=-9999){
          data[k]=int(EEPROM.read(50+i*ns+(late)*2))*256 + int(EEPROM.read(51+i*ns+(late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
          late++;
        }
        
        /*for(k=0;k<ns;k++){
            data[k]=int(EEPROM.read(50+(i+late)*2))<<8 + int(EEPROM.read(51+(i+late)*2)); //vet[50+(i+late)*2]<<8+vet[51+(i+late)*2];
            late++;
        }*/

        //envia epochsvd + data[ns]
        String prints=String(epochsvd) + ": "+ String(data[0]) + ", " + String(data[1]) + ", " + String(data[2]) + ", " + String(data[3]) + ", " + String(data[4]) + ", " + String(data[5]) + ", " + String(data[6]) + ", " + String(data[7]);
        Serial.println(prints);
        epochsvd+=300;
        n_data--;       
        
    }
    epochsvd=epochnow-300;
    n_data=int(EEPROM.read(30+i))*256 + int(EEPROM.read(31+i));  //vet[30+i]<<8+vet[31+i];
    dataPos=50+i*ns+2*ns*(n_data+n2_data)-1;
    
    y=0;
    while(n2_data!=0){
        k=7;
        if (tv3!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (tv2!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (tv1!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (sv5!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-k*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (sv4!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-k*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (sv3!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (sv2!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
        if (sv1!=-9999){
          data[k]=int(EEPROM.read(dataPos-1-y*2))*256+ int(EEPROM.read(dataPos-y*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
          y++;
        }
        k--;
              
        /*for(int k=ns-1;k>=0;k++){
            data[k]=int(EEPROM.read(50+(late+i+n2_data+k)*2))<<8+ int(EEPROM.read(51+(late+i+n2_data+k)*2));//vet[50+(late+i+n2_data+k)*2]<<8+vet[51+(late+i+n2_data+k)*2];
        }*/
        
        //envia epochsvd + data[ns]
        String prints=String(epochsvd) + ": "+ String(data[0]) + ", " + String(data[1]) + ", " + String(data[2]) + ", " + String(data[3]) + ", " + String(data[4]) + ", " + String(data[5]) + ", " + String(data[6]) + ", " + String(data[7]);
        Serial.println(prints);
        epochsvd-=300;
        n2_data--;
    }
    //envia epochnow + datanow
    String prints=String(epochnow) + ": "+ String(sv1) + ", " + String(sv2) + ", " + String(sv3) + ", " + String(sv4) + ", " + String(sv5) + ", " + String(tv1) + ", " + String(tv2) + ", " + String(tv3);
    Serial.println(prints);
    EEPROM.write(30+i, 0);     //vet[30+i]=(n_data+1)>>8;
    EEPROM.write(31+i, 0);     //vet[31+i]=(n_data+1);
    EEPROM.write(40+i, 0);     //vet[40+i]=(n2_data+1)>>8;
    EEPROM.write(41+i, 0);     //vet[41+i]=(n2_data+1);
    EEPROM.commit();
}


void EscreveEEPROM(int sv1,int sv2,int sv3,int sv4,int sv5,int tv1,int tv2,int tv3,long epochnow){
    int count=0,i=-2,n_data=0,n2_data,ns=0,dataPos=0,aux=0;
    long epochsvd=0;
    do{
        i+=2;
        count = int(EEPROM.read(0+i))*256 + int(EEPROM.read(1+i)); //count = vet[0+i]<<8+vet[1+i];
        Serial.println(count);
    }
    while(count>=8000);
    epochsvd=(((((EEPROM.read(10+2*i)*256) +EEPROM.read(11+2*i))*256) + EEPROM.read(12+2*i))*256) + EEPROM.read(13+2*i);   // (((((vet[10+2*i]*256)+vet[11+2*i])*256)+vet[12+2*i])*256)+vet[13+2*i];
    //n_data=EEPROM.read(30+i)<<8 + EEPROM.read(31+i);  //vet[30+i]<<8+vet[31+i];
    n_data=EEPROM.read(30+i)*256+EEPROM.read(31+i);
    n2_data=int(EEPROM.read(40+i))*256 + int(EEPROM.read(41+i)); //vet[40+i]<<8+vet[41+i];
    count+=1;
    EEPROM.write(0+i, count>>8); //et[0+i]=(count+1)>>8;           //Atualiza count
    EEPROM.write(1+i, count); //vet[1+i]=(count+1);
    //n_data=1;
    
    if (n_data==0){                 //Atualiza Epoch
        EEPROM.write(10+2*i, (epochnow)>>24); //vet[10+i] = epochnow>>24;
        EEPROM.write(11+2*i, (epochnow)>>16); //vet[11+i] = epochnow>>16;
        EEPROM.write(12+2*i, (epochnow)>>8); //vet[12+i] = epochnow>>8;
        EEPROM.write(13+2*i, (epochnow)); //vet[13+i] = epochnow;
    }
    ns=s1+s2+s3+s4+s5+t1+t2+t3;
    dataPos=50+i*ns+(n_data+n2_data)*ns*2;
    
    if(i+(n_data+n2_data)*2<memorylimit){
        aux=0;
        Serial.println(dataPos);
        if(sv1!=-9999){                      //Insere dados
            EEPROM.write(dataPos, sv1>>8); //vet[50+i+(n_data+n2_data)*2]=sv1>>8;
            EEPROM.write(dataPos+1, sv1); //vet[51+i+(n_data+n2_data)*2]=sv1&256;
            aux++;
        }
        if(sv2!=-9999){
            EEPROM.write(dataPos+aux*2, sv2>>8); //vet[50+i+(n_data+n2_data+ns)*2]=sv2>>8;
            EEPROM.write(dataPos+1+aux*2, sv2); //vet[51+i+(n_data+n2_data+ns)*2]=sv2&256;
            aux++;
        }
        if(sv3!=-9999){
            EEPROM.write(dataPos+aux*2, sv3>>8); //vet[50+i+(n_data+n2_data+ns)*2]=sv3>>8;
            EEPROM.write(dataPos+1+aux*2, sv3); //vet[51+i+(n_data+n2_data+ns)*2]=sv3&256;
            aux++;
        }
        if(sv4!=-9999){
            EEPROM.write(dataPos+aux*2, sv4>>8); //vet[50+i+(n_data+n2_data+ns)*2]=sv4>>8;
            EEPROM.write(dataPos+1+aux*2, sv4); //vet[51+i+(n_data+n2_data+ns)*2]=sv4&256;
            aux++;
        }
        if(sv5!=-9999){
            EEPROM.write(dataPos+aux*2, sv5>>8); //vet[50+i+(n_data+n2_data+ns)*2]=sv5>>8;
            EEPROM.write(dataPos+1+aux*2, sv5); //vet[51+i+(n_data+n2_data+ns)*2]=sv5&256;
            aux++;
        }
        if(tv1!=-9999){
            EEPROM.write(dataPos+aux*2, (tv1*100)>>8); //vet[50+i+(n_data+n2_data+ns)*2]=(tv1*100)>>8;
            EEPROM.write(dataPos+1+aux*2, (tv1*100)); //vet[51+i+(n_data+n2_data+ns)*2]=(tv1*100)&256;
            aux++;
        }
        if(tv2!=-9999){
            EEPROM.write(dataPos+aux*2, (tv2*100)>>8); //vet[50+i+(n_data+n2_data+ns)*2]=(tv2*100)>>8;
            EEPROM.write(dataPos+1+aux*2, (tv2*100)); //vet[51+i+(n_data+n2_data+ns)*2]=(tv2*100)&256;
            aux++;
        }
        if(tv3!=-9999){
            EEPROM.write(dataPos+aux*2, (tv3*100)>>8); //vet[50+i+(n_data+n2_data+ns)*2]=(tv3*100)>>8;
            EEPROM.write(dataPos+1+aux*2, (tv3*100)); //vet[51+i+(n_data+n2_data+ns)*2]=(tv3*100)&256;
            aux++;
        }
    }
    else{
        //erro! Memory overflow
    }
    if(resetFlag==0){               //Atualiza N1
      //Serial.println(n_data);
        EEPROM.write(30+i, (n_data+1)>>8); //vet[30+i]=(n_data+1)>>8;
        EEPROM.write(31+i, (n_data+1)); //vet[31+i]=(n_data+1);
    }
    else{                           //Atualiza N2
        EEPROM.write(40+i, (n2_data+1)>>8); //vet[40+i]=(n2_data+1)>>8;
        EEPROM.write(41+i, (n2_data+1)); //vet[41+i]=(n2_data+1);
    }
    EEPROM.commit();

}







void SaveData2(unsigned long epoch, unsigned char n, unsigned int pulse1, unsigned int pulse2, unsigned int pulse3, unsigned int pulse4, unsigned int pulse5){
  unsigned int i=0,count=0,savedData=0,savedData2=0,savedCount;
  unsigned long savedEpoch=0;
  while (((int(EEPROM.read(i))<<8)+int(EEPROM.read(i+1)))>=8000)            //identifica onde ta o contador
    i+=2;   
  if (i>=10){
    //retorna erro de máximo de escritas
  }
  count = ((int(EEPROM.read(i))<<8)+int(EEPROM.read(i+1)))+1;   
  savedData2=(int(EEPROM.read(40+i))<<8)+int(EEPROM.read(41+i));          //dado salvo sem epoch?
  EEPROM.write(i, (count)>>8);                                                //atualiza contador
  EEPROM.write((i+1), (count) & 0xff);
  savedEpoch = (((((EEPROM.read(10+2*i)<<8) +EEPROM.read(11+2*i))<<8) + EEPROM.read(12+2*i))<<8) + EEPROM.read(13+2*i); //le epoch salvo
  savedData=(EEPROM.read(30+i)<<8)+EEPROM.read(31+i);                       //dados salvos com epoch
  if(savedData+savedData2<2000){                                            //limite para proteger o final da memória 
    EEPROM.write((50+savedData*10+savedData2*10+i),pulse1>>8);                //salva pulse1
    EEPROM.write((51+savedData*10+savedData2*10+i),pulse1);
    EEPROM.write((52+savedData*10+savedData2*10+i),pulse2>>8);
    EEPROM.write((53+savedData*10+savedData2*10+i),pulse2);
    EEPROM.write((54+savedData*10+savedData2*10+i),pulse3>>8);
    EEPROM.write((55+savedData*10+savedData2*10+i),pulse3);
    EEPROM.write((56+savedData*10+savedData2*10+i),pulse4>>8);
    EEPROM.write((57+savedData*10+savedData2*10+i),pulse4);
    EEPROM.write((58+savedData*10+savedData2*10+i),pulse5>>8);
    EEPROM.write((59+savedData*10+savedData2*10+i),pulse5);
  }
  else{
    //retorna erro do limite de memória
  }
  if(savedData==0){                                                         //se não houver nada salvo, salva epoch
    EEPROM.write((10+i*2), epoch>>24);
    EEPROM.write((11+i*2), epoch>>16);
    EEPROM.write((12+i*2), epoch>>8);
    EEPROM.write((13+i*2), epoch);
  }
  if(flag==0){                                                              //se não tem internet e recém ligou...
    EEPROM.write(40+i,(savedData2+1)>>8);
    EEPROM.write(41+i,(savedData2+1));
  }
  else{
    EEPROM.write(30+i,(savedData+1)>>8);
    EEPROM.write(31+i,(savedData+1));
  }
  
  EEPROM.commit();
}
