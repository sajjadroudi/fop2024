#include<stdio.h>

int sum(int x){
	int sum1=0, n=0;
	while(x>0){
		n=x%10;
		x=x/10;
		sum1=sum1+n;

	}
	return sum1;
}



int prime(int n){
	int sum2=0,i,o=0,j;
	if(n==2){
		return 2;
		}
	else{
		for(i=2;i<=n;i++){
			o=0;
			if(n%i==0){
				for(j=2;j<i;j++){
					if(i%j==0){
						o++;
					}
				}
				if(o==0){
					sum2=sum2+i;
				}
			}
	}
	return sum2;
}
}

int main(){
	int t, n=0, i, j, d=0, p=0;
	scanf("%d",&t);
	int a[t];
	for(i=0;i<t;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<t;i++){
		p=0;
		n=a[i];
		for(j=2;j<n;j++){
			d=j+prime(j)+sum(j);
			if(d==n){
				printf("Yes\n");
				p=1;
				break;
			}
		}
		if(p==0){
			printf("No\n");
		}
	}
}





