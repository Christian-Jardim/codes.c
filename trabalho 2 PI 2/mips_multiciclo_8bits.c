  case 1: //Estado 1
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    decodificarInstrucao(r->ri,in,d);
    printInstrucao(d);
    r->a = r->br[d->rs];
    r->b = r->br[d->rt];
    ULA(ULA_op1(*est,r->a,r->pc),ULA_op2(*est,r->b,d->imm),0,saida);
    r->ula_saida = saida->resultado;
    if(d->opcode == 2) {
      copiarBits(r->ri, in->addr, 8, 8);
      jump = binarioParaDecimal(in->addr, 0);
    }
    estado(est,d->opcode);
    break;

  case 2: //Estado 2 - executa lw,sw e addi
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    if(d->opcode == 11 || d->opcode == 15) {
      ULA(r->a, d->imm, 0,saida);
      r->ula_saida = saida->resultado;
    }

    if(d->opcode == 4) {
      ULA(r->a, d->imm, 0,saida);
      r->ula_saida = saida->resultado;
    }
    estado(est,d->opcode);
    break;

  case 3: //Estado 3 - acessa a memC3ria (lw)
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    strcpy(r->rdm, mem[r->ula_saida+128]);
    estado(est,d->opcode);
    break;

  case 4: //Estado 4 - escreve no registrador (lw)
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    r->br[d->rt] = binarioParaDecimal(r->rdm, 1);
    estado(est,d->opcode);
    break;

  case 5: //Estado 5 - escreve na memória
    empilha(p, d, mem, r, est);
    controle(d->opcode, est, s);
    int_para_binario(r->b, binario);
    strcpy(mem[r->ula_saida+128], binario);
    estado(est, d->opcode);
    break;

  case 6: //Estado 6 - escreve no registrador (addi)
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    r->br[d->rt] = r->ula_saida;
    estado(est,d->opcode);
    break;

  case 7: //Estado 7 - executa r
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    ULA(r->a, r->b, d->funct,saida);
    r->ula_saida = saida->resultado;
    estado(est,d->opcode);
    break;

  case 8: //Estado 8 - escreve no registrador (r)
    empilha(p,d,mem,r,est);
    controle(d->opcode,est,s);
    r->br[d->rd] = r->ula_saida;
    estado(est,d->opcode);
    break;

  case 9: //Estado 9 - executa beq
    empilha(p, d, mem, r, est);
    controle(d->opcode, est, s);
    ULA(r->a, r->b, 2, saida);
    if (saida->flag_zero == 1) {
        r->pc = r->ula_saida;
    }
    estado(est, d->opcode);
    break;

  case 10: //Estado 10 - executa jump
    empilha(p, d, mem, r, est);
    controle(d->opcode, est, s);
    r->pc = d->addr;
    estado(est, d->opcode);
    break;

  default:
    printf("ESTADO DESCONHECIDO");
    return 0;
    break;
  }
}