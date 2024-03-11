#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	
	if (!s1 || !s2) 
	{
		return (0);
	}
	while(*s1)							/* strpbrk trazi prvi karakter koji moze */
	{									/* pronaci da je i u s2. Odatle printa sve */
		i = 0;							/* ostale karaktete. Primjer ako je */
	   	while(s2[i])					/* s1="ja sam visoka 2 metra" i s2="2" */
		{								/* rezultat je "2 metra visoka" */
			if(*s1 == s2[i])			
				return (char *) s1;		
			i++;					
		}								
		s1++;	
	}
	return (0);
}
