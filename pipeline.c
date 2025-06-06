void controle(int opcode, int funct, Sinais *sinais) {
    if(opcode == 0) {
        if(funct == 0) {
        sinais->EscPC =
	    sinais->RegDest =
	    sinais->ULAOp =
	    sinais->ULAFonte =
	    sinais->DC =
	    sinais->DI =
	    sinais->EscMem =
	    sinais->EscReg =
	    sinais->MemParaReg =
        }
    }
}