for(i = 0; i < T; i++){//ler os valores
        fflush(stdin);
        printf("\nDigite qual o tipo do voo: ");
        scanf("%c", &ler);
        printf("\nDigite o numero do voo: ");
        scanf("%d", &valid);
        if(ler == 80 || ler == 2){//Força a inclusao do tipo do voo
            printf("\nDigite a prioridade: ");
            scanf("%d", &valpriority);
            push(&Plane, valid, valpriority, 'P');
        }
        else
            push(&Plane, valid, 3, 'D');
    }
