# push_swap
42 project push_swap 

Algo a_to_b
1. Je mets tous les chiffres dans un tableau et je les range en ordre croissant.
2. Une fois c’est range, je choisis deux pivots. (Dans les deux fonctions sort_a_to_b et sort_b_to_a)
    * Un pivot, qui s’appelle big_p (variable), qui est le chiffre au milieu des chiffres.
    * Un autre pivot, qui s’appelle small_p (variable), qui est le chiffre a un tier des chiffres.

			|———————————————————|—————————————————|———————————————————————————————————|
		                        A                 B     
            A: Small_p
            b: big_p

3. Dans A to B (피봇보다 큰 숫자를 a에 남기고 피봇보다 작은 숫자를 b로 보내면서 정렬하는 방법)
    * Si la première valeur de A est
        * Plus grande ou égale que big_p -> ra (la renvoyer derrière de A et elle reste dans A)
        * Plus petite que big_p -> pb (la renvoyer à B)
            * Dans les valeurs qui s’est fait pb, si elle est 
                * plus grande ou égale que small_p -> rb (la renvoyer derrière de B)

		A		|————————————————————————————————————————|
         
        les valeurs plus grandes/égale que big_pivot(ra)

		B		|—————————————————————|———————————————————|
				                     
        les valeurs plus petite que small_pivot(pb-rb)      
        les valuers plus grande/egale que small_pivot(rb)	

    * Ensuite, fait rra et rrb avant d’entrer dans la fonctions recursive.
    * Avec la fonctions recursive, les valeurs sont déménagés vers B jusqu’il reste 1,2,3,5 nombre de valeurs reste dans A. (quand il reste que 1,2,3,5 nombre de valeurs, ça va ranger en ordre croissant et ça sort de la fonctions recursive)

4. Dans B to A (피봇보다 큰 숫자를 a로 우선 보내고, 작은 숫자를 내림차순으로 정렬해 a로 pa에 정렬하는 방법) 
    * Si la premiere valuer de B est
        * Plus petite que small_p  -> rb (la renvoyer derrière de B et elle reste dans B)
        * Plus grande ou égale que small_p -> pa (la renvoyer a A)
            * Dans les valeurs qui s’est fait pa, si elle est
                * Plus petite que big_p -> ra (la renvoyer derrière de A

		A		|——————————————|———————————|———————————————|
				les valeurs plus grandes/			chiffres rangés			les valeurs plus petites
				égale que big_pivot(pa-ra)										que big_pivot(ra)

		B		|——————————————|———————————————————————————|
					chiffres ranges 							les valeurs plus petite que small_pivot(rb)	

    * Avant de faire rra, rrb, il faut ranger les chiffres qui se sont fait ra. Sinon on peut pas ranger ces chiffres.
    * Ensuite, fait rra et rrb avant d’entrer dans la fonctions recursive.
    * Avec la fonctions recursive, les valeurs sont déménagés vers A jusqu’il reste 1,2,3,5 nombre de valeurs reste dans A. (quand il reste que 1,2,3,5 nombre de valeurs, ça va ranger en ordre croissant et ça sort de la fonctions recursive)
