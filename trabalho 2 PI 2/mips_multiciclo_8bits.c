empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
		escreve_ri(r->ri,s->EscRI,mem[IOuD(s->IouD,r->pc,d->imm)]);
    strcpy(r->rdm,mem[IOuD(s->IouD,r->pc,d->imm)]);
    decodificarInstrucao(r->ri,in,d);
    printInstrucao(d);
    r->a = r->br[d->rs];
    r->b = r->br[d->rt];
   ULA(ULA_op1(*est,r->a,r->pc),ULA_op2(*est,r->b,d->imm),0,saida);
		r->ula_saida = saida->resultado; 
		escreve_pc(&r->pc, s->EscPC, PCFonte(saida->resultado, r->ula_saida, s->FontePC), s->Branch, saida->flag_zero);
    if(d->opcode == 2) {
      copiarBits(r->ri, in->addr, 8, 8);
      jump = binarioParaDecimal(in->addr, 0);
    }
    estado(est,d->opcode);