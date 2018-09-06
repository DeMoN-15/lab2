#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(){
  FILE *file;
  file=fopen("input.txt","r");
  char c,str[10],o;
  char keyword[32][10]={"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","voltile","do","if","static","while"} ;
  int num,i=0,j=0,k=0,flag=0,oflag=0;
  c=getc(file);
  while((c!=EOF))
    {
      if(isdigit(c))
	{
	  num=c-48;
	  c=getc(file);
	  while(isdigit(c))
	    {
	      num=num*10+(c-48);
	      c=getc(file);
	    }
	  ungetc(c,file);
	  printf("%d integer\n",num);

	}
      if(isalpha(c)){
	str[i++]=c;
	c=getc(file);
	while(isalpha(c)||isdigit(c)||c=='-'||c=='$'){
	  str[i++]=c;
	  c=getc(file);
	}
	str[i++]='\0';
	
	for(j=0;j<32;j++)
	  {
	    if(strcmp(str,keyword[j])==0)
	      
	      {
		flag=1;
	      }
	  }
	if(flag==1){
	  printf("%s is a keyword\n",str);
	  flag=0;
	}
	else
	  printf("%s is an identifier\n",str);
	i=0;
      }else
	{
	  o=c;
	  if(o=='+'||o=='-'||o=='*'||o=='/'||o=='='){
	    oflag=1;
	  }
	  if(oflag){
	    printf("%c is an operator\n",c);
	    oflag=0;
	  }
	  if(o=='#'||o=='@'||o=='%'||o=='&'||o=='^'||o=='('||o==')'){
	  printf("%c it is special character\n",o);
	}	  
	}
      c=getc(file);
    }
  return 0;
}
