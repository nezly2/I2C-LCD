void LCD_parse (char* letra, unsigned char caracter){
	switch (caracter){
		case 'a': case 'A':
			letra[0] = 0x00;
			letra[1] = 0xFC;
			letra[2] = 0x12;
			letra[3] = 0x11;
			letra[4] = 0x12;
			letra[5] = 0xFC;
			letra[6] = 0x00;
			break;

		case 'b': case 'B':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x89;
			letra[3] = 0x89;
			letra[4] = 0x8E;
			letra[5] = 0x70;
			letra[6] = 0x00;
			break;

		case 'c': case 'C':
			letra[0] = 0x00;
			letra[1] = 0x7E;
			letra[2] = 0x81;
			letra[3] = 0x81;
			letra[4] = 0x81;
			letra[5] = 0x42;
			letra[6] = 0x00;
			break;

		case 'd': case 'D':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x81;
			letra[3] = 0x81;
			letra[4] = 0x42;
			letra[5] = 0x3C;
			letra[6] = 0x00;
			break;

		case 'e': case 'E':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x89;
			letra[3] = 0x89;
			letra[4] = 0x89;
			letra[5] = 0x81;
			letra[6] = 0x00;
			break;

		case 'f': case 'F':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x09;
			letra[3] = 0x09;
			letra[4] = 0x09;
			letra[5] = 0x01;
			letra[6] = 0x00;
			break;

		case 'g': case 'G':
			letra[0] = 0x00;
			letra[1] = 0x7E;
			letra[2] = 0x81;
			letra[3] = 0x91;
			letra[4] = 0x91;
			letra[5] = 0x70;
			letra[6] = 0x00;
			break;

		case 'h': case 'H':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x08;
			letra[3] = 0x08;
			letra[4] = 0x08;
			letra[5] = 0xFF;
			letra[6] = 0x00;
			break;

		case 'i': case 'I':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x81;
			letra[3] = 0xFF;
			letra[4] = 0x81;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case 'j': case 'J':
			letra[0] = 0x00;
			letra[1] = 0x40;
			letra[2] = 0x80;
			letra[3] = 0xFF;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case 'k': case 'K':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x18;
			letra[3] = 0x24;
			letra[4] = 0x42;
			letra[5] = 0x81;
			letra[6] = 0x00;
			break;

		case 'l': case 'L':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0xFF;
			letra[3] = 0x80;
			letra[4] = 0x80;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case 'm': case 'M':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x06;
			letra[3] = 0x0C;
			letra[4] = 0x06;
			letra[5] = 0xFF;
			letra[6] = 0x00;
			break;

		case 'n': case 'N':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x06;
			letra[3] = 0x08;
			letra[4] = 0x30;
			letra[5] = 0xFF;
			letra[6] = 0x00;
			break;

		case 'o': case 'O':
			letra[0] = 0x00;
			letra[1] = 0x7E;
			letra[2] = 0x81;
			letra[3] = 0x81;
			letra[4] = 0x81;
			letra[5] = 0x7E;
			letra[6] = 0x00;
			break;

		case 'p': case 'P':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x09;
			letra[3] = 0x09;
			letra[4] = 0x09;
			letra[5] = 0x06;
			letra[6] = 0x00;
			break;

		case 'q': case 'Q':
			letra[0] = 0x00;
			letra[1] = 0x7E;
			letra[2] = 0x85;
			letra[3] = 0x89;
			letra[4] = 0xB1;
			letra[5] = 0x7E;
			letra[6] = 0x40;
			break;

		case 'r': case 'R':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x19;
			letra[3] = 0x29;
			letra[4] = 0x49;
			letra[5] = 0x86;
			letra[6] = 0x00;
			break;

		case 's': case 'S':
			letra[0] = 0x00;
			letra[1] = 0x4E;
			letra[2] = 0x89;
			letra[3] = 0x89;
			letra[4] = 0x89;
			letra[5] = 0x72;
			letra[6] = 0x00;
			break;

		case 't': case 'T':
			letra[0] = 0x00;
			letra[1] = 0x01;
			letra[2] = 0x01;
			letra[3] = 0xFF;
			letra[4] = 0x01;
			letra[5] = 0x01;
			letra[6] = 0x00;
			break;

		case 'u': case 'U':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x80;
			letra[3] = 0x80;
			letra[4] = 0x80;
			letra[5] = 0xFF;
			letra[6] = 0x00;
			break;

		case 'v': case 'V':
			letra[0] = 0x00;
			letra[1] = 0x3F;
			letra[2] = 0x40;
			letra[3] = 0x80;
			letra[4] = 0x40;
			letra[5] = 0x3F;
			letra[6] = 0x00;
			break;

		case 'w': case 'W':
			letra[0] = 0x00;
			letra[1] = 0xFF;
			letra[2] = 0x40;
			letra[3] = 0x20;
			letra[4] = 0x40;
			letra[5] = 0xFF;
			letra[6] = 0x00;
			break;

		case 'x': case 'X':
			letra[0] = 0x81;
			letra[1] = 0x42;
			letra[2] = 0x24;
			letra[3] = 0x18;
			letra[4] = 0x24;
			letra[5] = 0x42;
			letra[6] = 0x81;
			break;

		case 'y': case 'Y':
			letra[0] = 0x00;
			letra[1] = 0x03;
			letra[2] = 0x04;
			letra[3] = 0xFC;
			letra[4] = 0x04;
			letra[5] = 0x03;
			letra[6] = 0x00;
			break;

		case 'z':  case 'Z':
			letra[0] = 0x00;
			letra[1] = 0xE1;
			letra[2] = 0x91;
			letra[3] = 0x89;
			letra[4] = 0x85;
			letra[5] = 0x83;
			letra[6] = 0x00;
			break;

		case '-':  //ñ
			letra[0] = 0x00;
			letra[1] = 0xFC;
			letra[2] = 0x09;
			letra[3] = 0x11;
			letra[4] = 0x21;
			letra[5] = 0xFC;
			letra[6] = 0x00;
			break;

		case '.':
			letra[0] = 0xC0;
			letra[1] = 0xC0;
			letra[2] = 0x00;
			letra[3] = 0x00;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case ':':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x00;
			letra[3] = 0x66;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '=':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x28;
			letra[3] = 0x28;
			letra[4] = 0x28;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '1':
			letra[0] = 0x00;
			letra[1] = 0x04;
			letra[2] = 0x02;
			letra[3] = 0xFF;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '2':
			letra[0] = 0x00;
			letra[1] = 0xE2;
			letra[2] = 0x91;
			letra[3] = 0x89;
			letra[4] = 0x86;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '3':
			letra[0] = 0x00;
			letra[1] = 0x42;
			letra[2] = 0x81;
			letra[3] = 0x99;
			letra[4] = 0x66;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '4':
			letra[0] = 0x00;
			letra[1] = 0x18;
			letra[2] = 0x14;
			letra[3] = 0x12;
			letra[4] = 0xFF;
			letra[5] = 0x10;
			letra[6] = 0x00;
			break;

		case '5':
			letra[0] = 0x00;
			letra[1] = 0x4F;
			letra[2] = 0x89;
			letra[3] = 0x89;
			letra[4] = 0x89;
			letra[5] = 0x70;
			letra[6] = 0x00;
			break;

		case '6':
			letra[0] = 0x00;
			letra[1] = 0x7E;
			letra[2] = 0x89;
			letra[3] = 0x89;
			letra[4] = 0x89;
			letra[5] = 0x70;
			letra[6] = 0x00;
			break;

		case '7':
			letra[0] = 0x00;
			letra[1] = 0x01;
			letra[2] = 0x09;
			letra[3] = 0x09;
			letra[4] = 0xFF;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '8':
			letra[0] = 0x00;
			letra[1] = 0x66;
			letra[2] = 0x99;
			letra[3] = 0x99;
			letra[4] = 0x99;
			letra[5] = 0x66;
			letra[6] = 0x00;
			break;

		case '9':
			letra[0] = 0x00;
			letra[1] = 0x06;
			letra[2] = 0x09;
			letra[3] = 0x09;
			letra[4] = 0xFE;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case '0':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x7E;
			letra[3] = 0x81;
			letra[4] = 0x7E;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		case ' ':
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x00;
			letra[3] = 0x00;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;

		default:
			letra[0] = 0x00;
			letra[1] = 0x00;
			letra[2] = 0x00;
			letra[3] = 0x00;
			letra[4] = 0x00;
			letra[5] = 0x00;
			letra[6] = 0x00;
			break;
	}
}
