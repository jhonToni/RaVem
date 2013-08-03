/*
 * RAVEM.c
 *
 *  Created on:	return 2013/07/18
 *      Author:	return lynxeyed
 */
#include <stdio.h>
#include <string.h>
#include "ravem.h"

const unsigned char vm_array[] = {
0xCA, 0xFE, 0xBA, 0xBE, 0x00, 0x00, 0x00, 0x32, 0x00, 0x34, 0x0A, 0x00, 0x0C, 
0x00, 0x17, 0x09, 0x00, 0x18, 0x00, 0x19, 0x08, 0x00, 0x1A, 0x0A, 0x00, 0x1B, 0x00, 0x1C, 0x09, 
0x00, 0x18, 0x00, 0x1D, 0x0A, 0x00, 0x1E, 0x00, 0x1F, 0x0A, 0x00, 0x1B, 0x00, 0x20, 0x07, 0x00, 
0x21, 0x09, 0x00, 0x18, 0x00, 0x22, 0x08, 0x00, 0x23, 0x07, 0x00, 0x24, 0x07, 0x00, 0x25, 0x01, 
0x00, 0x06, 0x3C, 0x69, 0x6E, 0x69, 0x74, 0x3E, 0x01, 0x00, 0x03, 0x28, 0x29, 0x56, 0x01, 0x00, 
0x04, 0x43, 0x6F, 0x64, 0x65, 0x01, 0x00, 0x0F, 0x4C, 0x69, 0x6E, 0x65, 0x4E, 0x75, 0x6D, 0x62, 
0x65, 0x72, 0x54, 0x61, 0x62, 0x6C, 0x65, 0x01, 0x00, 0x04, 0x6D, 0x61, 0x69, 0x6E, 0x01, 0x00, 
0x16, 0x28, 0x5B, 0x4C, 0x6A, 0x61, 0x76, 0x61, 0x2F, 0x6C, 0x61, 0x6E, 0x67, 0x2F, 0x53, 0x74, 
0x72, 0x69, 0x6E, 0x67, 0x3B, 0x29, 0x56, 0x01, 0x00, 0x0D, 0x53, 0x74, 0x61, 0x63, 0x6B, 0x4D, 
0x61, 0x70, 0x54, 0x61, 0x62, 0x6C, 0x65, 0x07, 0x00, 0x21, 0x01, 0x00, 0x0A, 0x53, 0x6F, 0x75, 
0x72, 0x63, 0x65, 0x46, 0x69, 0x6C, 0x65, 0x01, 0x00, 0x0A, 0x68, 0x6F, 0x67, 0x65, 0x31, 0x2E, 
0x6A, 0x61, 0x76, 0x61, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0x07, 0x00, 0x26, 0x0C, 0x00, 0x27, 0x00, 
0x28, 0x01, 0x00, 0x0D, 0x65, 0x6E, 0x74, 0x65, 0x72, 0x20, 0x61, 0x6E, 0x79, 0x20, 0x6B, 0x65, 
0x79, 0x07, 0x00, 0x29, 0x0C, 0x00, 0x2A, 0x00, 0x2B, 0x0C, 0x00, 0x2C, 0x00, 0x2D, 0x07, 0x00, 
0x2E, 0x0C, 0x00, 0x2F, 0x00, 0x30, 0x0C, 0x00, 0x31, 0x00, 0x32, 0x01, 0x00, 0x13, 0x6A, 0x61, 
0x76, 0x61, 0x2F, 0x69, 0x6F, 0x2F, 0x49, 0x4F, 0x45, 0x78, 0x63, 0x65, 0x70, 0x74, 0x69, 0x6F, 
0x6E, 0x0C, 0x00, 0x33, 0x00, 0x28, 0x01, 0x00, 0x05, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x01, 0x00, 
0x05, 0x68, 0x6F, 0x67, 0x65, 0x31, 0x01, 0x00, 0x10, 0x6A, 0x61, 0x76, 0x61, 0x2F, 0x6C, 0x61, 
0x6E, 0x67, 0x2F, 0x4F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x01, 0x00, 0x10, 0x6A, 0x61, 0x76, 0x61, 
0x2F, 0x6C, 0x61, 0x6E, 0x67, 0x2F, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x01, 0x00, 0x03, 0x6F, 
0x75, 0x74, 0x01, 0x00, 0x15, 0x4C, 0x6A, 0x61, 0x76, 0x61, 0x2F, 0x69, 0x6F, 0x2F, 0x50, 0x72, 
0x69, 0x6E, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6D, 0x3B, 0x01, 0x00, 0x13, 0x6A, 0x61, 0x76, 
0x61, 0x2F, 0x69, 0x6F, 0x2F, 0x50, 0x72, 0x69, 0x6E, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6D, 
0x01, 0x00, 0x07, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x6C, 0x6E, 0x01, 0x00, 0x15, 0x28, 0x4C, 0x6A, 
0x61, 0x76, 0x61, 0x2F, 0x6C, 0x61, 0x6E, 0x67, 0x2F, 0x53, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x3B, 
0x29, 0x56, 0x01, 0x00, 0x02, 0x69, 0x6E, 0x01, 0x00, 0x15, 0x4C, 0x6A, 0x61, 0x76, 0x61, 0x2F, 
0x69, 0x6F, 0x2F, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6D, 0x3B, 0x01, 
0x00, 0x13, 0x6A, 0x61, 0x76, 0x61, 0x2F, 0x69, 0x6F, 0x2F, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x53, 
0x74, 0x72, 0x65, 0x61, 0x6D, 0x01, 0x00, 0x04, 0x72, 0x65, 0x61, 0x64, 0x01, 0x00, 0x03, 0x28, 
0x29, 0x49, 0x01, 0x00, 0x05, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x01, 0x00, 0x04, 0x28, 0x43, 0x29, 
0x56, 0x01, 0x00, 0x03, 0x65, 0x72, 0x72, 0x00, 0x20, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x0E, 0x00, 0x01, 0x00, 0x0F, 0x00, 0x00, 0x00, 
0x1D, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x2A, 0xB7, 0x00, 0x01, 0xB1, 0x00, 0x00, 
0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x09, 
0x00, 0x11, 0x00, 0x12, 0x00, 0x01, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x02, 0x00, 0x03, 
0x00, 0x00, 0x00, 0x26, 0xB2, 0x00, 0x02, 0x12, 0x03, 0xB6, 0x00, 0x04, 0xB2, 0x00, 0x05, 0xB6, 
0x00, 0x06, 0x3C, 0xB2, 0x00, 0x02, 0x1B, 0x92, 0xB6, 0x00, 0x07, 0xA7, 0xFF, 0xF1, 0x4D, 0xB2, 
0x00, 0x09, 0x12, 0x0A, 0xB6, 0x00, 0x04, 0xA7, 0xFF, 0xE5, 0x00, 0x01, 0x00, 0x08, 0x00, 0x17, 
0x00, 0x1A, 0x00, 0x08, 0x00, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x07, 0x00, 0x00, 
0x00, 0x06, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0F, 0x00, 0x0A, 0x00, 0x17, 0x00, 0x0E, 0x00, 0x1A, 
0x00, 0x0C, 0x00, 0x1B, 0x00, 0x0D, 0x00, 0x23, 0x00, 0x0E, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 
0x00, 0x02, 0x08, 0x51, 0x07, 0x00, 0x14, 0x00, 0x01, 0x00, 0x15, 0x00, 0x00, 0x00, 0x02, 0x00, 
0x16, 0x00, 0x00, 0x00
};

char cp_str[32];
uint8_t bc_str[32];
int32_t total_const_pool_num;

uint8_t *bc_seek(int bc_num, int length){
	memcpy(bc_str, &vm_array[bc_num],length);
	return bc_str;
}

int32_t getLengthOfConstantInfo(uint8_t constantType)
{
	switch (constantType) {

		case CONSTANT_Class:		
		case CONSTANT_String:		
		case CONSTANT_MethodType:		
		case CONSTANT_InvokeDynamic:	
			return	3;

		case CONSTANT_Fieldref:
		case CONSTANT_Methodref:
		case CONSTANT_InterfaceMethodref:
		case CONSTANT_Integer:		
		case CONSTANT_Float:	
		case CONSTANT_MethodHandle:
		case CONSTANT_NameAndType:
			return	5;
	 
		case CONSTANT_Long:		
		case CONSTANT_Double:		
			return	9;
	 
		case CONSTANT_Utf8:		
			return	(-1);		//4 or more (see 'length')

	 default:
		 return 0;
	}
}

const_pool_t getConstantPoolInfo(int const_num){
	
	const_pool_t c;
	int i=0, j=1, length;

	total_const_pool_num = (*bc_seek(8,1)<<8) + *bc_seek(9,1);

	if ((const_num ==0)||(const_num >= total_const_pool_num))
	{
		c.index = 0;
		return c;
	}
	
	while(1)
	{
		c.tab = *bc_seek(10+i,1);	// tab
		length = getLengthOfConstantInfo(*bc_seek(10+i,1));
		
		if(length==-1)// Constant_UTF8
		{
			length = ((*bc_seek(11+i,1)<<8) + *bc_seek(12+i,1)) + 3 /* tag + length = 3byte*/ ; 		
		}

		if(j == const_num)break;
		if((c.tab == CONSTANT_Long)||(c.tab == CONSTANT_Double)){
			j = j + 2;
		}else{
			j = j + 1;
		}
			
		if(j >= total_const_pool_num)break;
		i += length;
	}

	c.index = ((*bc_seek(11+i,1)<<8) + *bc_seek(12+i,1));
	c.index2 = ((*bc_seek(13+i,1)<<8) + *bc_seek(14+i,1));
	c.bc_num = 10 + i; //todo: fix this
	switch(c.tab)
	{
		case CONSTANT_Utf8:
		//case CONSTANT_Double:
		//case CONSTANT_Float:
		//case CONSTANT_Long:
		//case CONSTANT_Integer:
			memcpy((char*)cp_str,  bc_seek(13+i,c.index), c.index);
		  cp_str[c.index] = '\0';
			c.stack_pt = (char *)&cp_str;
			break;
		
		default:
			break;
					
	}
	
	return c;
}

//seek class_name_index,Strings,Numerics from Constant Pool 
const_pool_t seekConstClassNumString(int const_num)
{
	const_pool_t c;
	c = getConstantPoolInfo(const_num);
	
	switch (c.tab)
	{
		case CONSTANT_String:
		case CONSTANT_Class:
			c = getConstantPoolInfo(c.index);
			break;
		
		default:
			break;
	}		
	return c;
}


// for methodref & Fieldref 
const_pool_t seekClassIndex(int const_num){
	const_pool_t c;
	c = getConstantPoolInfo(const_num);
	
	switch(c.tab)
	{
		case CONSTANT_Methodref:
		case CONSTANT_Fieldref:
			c = seekConstClassNumString(c.index);
			break;
		
		default:
			break;	// in fact,we must program in error process but tedious;-P 
	}
	
	return c;
}

// For NameAndType:name index
const_pool_t seekNameAndType_name(int const_num){
	const_pool_t c;
	c = getConstantPoolInfo(const_num);
	
	
	switch(c.tab)
	{
		case CONSTANT_Methodref:
		case CONSTANT_Fieldref:
			c = getConstantPoolInfo(c.index2); //Constant_NAmeAndType
			// do not insert break; here
		
		case CONSTANT_NameAndType:
			c = seekConstClassNumString(c.index);
			break;
		
		default:
			break;	// in fact,we must program in error process but tedious;-P 			
	}
	return c;
}


// For NameAndType:descriptor
const_pool_t seekNameAndType_desc(int const_num){
	const_pool_t c;
	c = getConstantPoolInfo(const_num);
	
	switch(c.tab)
	{
		case CONSTANT_Methodref:
		case CONSTANT_Fieldref:
			c = getConstantPoolInfo(c.index2);		// Constant_NAmeAndType
			c = seekConstClassNumString(c.index2);
			break;
		
		case CONSTANT_NameAndType:
			c = seekConstClassNumString(c.index2);
			break;
		
		default:
			break;
			
	}
	return c;
}

class_st seekCodeArrtibute(char* method_name,int strlen)
{
	int i,j;
	int length,cmp;
	volatile int pointr;
	int attribute_length, attributes_count, methods_count;
	
	const_pool_t z;
	class_st cl;
	cl.code_length = 0;
	
	// get length of Constant_pool[last_num]
	z = getConstantPoolInfo(total_const_pool_num - 1);
	
	if(z.tab == CONSTANT_Utf8) length = z.index + 3; else length = getLengthOfConstantInfo(z.tab);
	
	pointr = z.bc_num + length;
	
	// seek pointr to interfaces_count 
	pointr +=  
					+ 2		// access_flag
					+ 2		// this_class
					+ 2		// super_class
					;
	
	pointr += ((*bc_seek(pointr,1) << 8) + *bc_seek(pointr + 1,1)) + 2; // 2 = length of 'interfaces_count' 			
					
	// now, pointr's locate is fields_count(2bytes)
	pointr += ((*bc_seek(pointr,1) << 8) + *bc_seek(pointr + 1,1)) + 2;
	
	// now, pointr's locate is methods_count(2bytes)
	methods_count = ((*bc_seek(pointr,1) << 8) + *bc_seek(pointr + 1,1));
	pointr += 2;	// method info (access_flag)
		
	for(i = 0 ; i < methods_count; i++)
	{
	
		pointr += 2;	// name_index
		
		z = getConstantPoolInfo((*bc_seek(pointr,1)<<8)+*bc_seek(pointr + 1,1));
		cmp = strncmp(z.stack_pt,method_name,strlen);
		
		pointr += 2; //descriptor_index;
		pointr += 2;
		
		attributes_count = ((*bc_seek(pointr,1) << 8) + *bc_seek(pointr + 1,1));
		pointr += 2; //attributes_count;
		
		for(j = 0 ; j < attributes_count ; j++)
		{
			pointr = pointr + 2; //attribute_name_index
			attribute_length  = (*bc_seek(pointr,1) << 24)
													+ (*bc_seek(pointr + 1,1) << 16)
													+ (*bc_seek(pointr + 2,1) << 8)
													+  *bc_seek(pointr + 3,1)
													;
			
			pointr += 4;  //attribute_length
			if(!cmp)
			{
				cl.stack_num   = (*bc_seek(pointr,1) << 8)   + *bc_seek(pointr+1,1);
				cl.local_num   = (*bc_seek(pointr+2,1) << 8) + *bc_seek(pointr+3,1);
				cl.code_length = (*bc_seek(pointr + 4,1) << 24)
													+ (*bc_seek(pointr + 5,1) << 16)
													+ (*bc_seek(pointr + 6,1) << 8)
													+  *bc_seek(pointr + 7,1)
													;
				cl.bc_offset = pointr + 8;
				cl.code_offset = 0;
			}
			pointr += attribute_length; // code attribute
		}
	}
	return cl;
}

char* getStringFromOperandStack(class_st cl)
{
	int i;
	const_pool_t cp;
	
	for(i = 0 ; i < cl.stack_num ; i++){
		if(cl.op_stack_type[i]==0){ 		// seek top of stack
			if(i == 0)return NULL;	// return NULL if operand stack has no stack 
			break; 
		}
	}
	i = i - 1;
	
	if(cl.op_stack_type[i] == Stack_ConstantPool){
		cp = seekConstClassNumString(cl.op_stack[i]);
		cl.op_stack_type[i] = Stack_Nothing;
		return cp.stack_pt;
	}
	if(cl.op_stack_type[i] == Stack_IntType){
		cl.op_stack_type[i] = Stack_Nothing;
		sprintf(cp_str,"%d",cl.op_stack[i]);
		return cp_str;
	}
	if(cl.op_stack_type[i] == Stack_CharType){
		cl.op_stack_type[i] = Stack_Nothing;
		sprintf(cp_str,"%c",(char)cl.op_stack[i]);
		return cp_str;
	}
	if(cl.op_stack_type[i] == Stack_Field){
		if(cl.field_mem_reg == NULL) return NULL;
		cl.op_stack_type[i] = Stack_Nothing;
		return cl.field_mem_reg;
	}
	return NULL;
}

int getIntegerFromOperandStack(class_st cl){
	int i;
	const_pool_t cp;
	
	for(i = 0 ; i < cl.stack_num ; i++){
			if(cl.op_stack_type[i]==0){ // seek top of stack
			if(i == 0)return 0;
			break; 
		}
	}
	i = i - 1;
			
	if(cl.op_stack_type[i] == Stack_ConstantPool){ // Const_Integer
		cp = seekConstClassNumString(cl.op_stack[i]);
		cl.op_stack_type[i] = 0;
		return ((cp.index<<16) + cp.index2); 
	}
	
	if(cl.op_stack_type[i] == Stack_IntType){		// stack direct
		cl.op_stack_type[i] = 0;
		return cl.op_stack[i];
	}
	return 0;
}

class_st setStackFromConstantPool(class_st cl, int cp_num){
	
	int i;
	for(i=0 ; i < cl.stack_num ; i++){		
		if(cl.op_stack_type[i]==0){ 							// seek top of stack
			break; 
		}
	}
	
	if((i == cl.stack_num - 1)&&(cl.op_stack_type[i]!=0))
		return cl;// stack full
	
	cl.op_stack_type[i] = Stack_ConstantPool;
	cl.op_stack[i] = cp_num;
	i = i + 1;
	if(i == cl.stack_num)
		return cl;
	else 
		cl.op_stack_type[i] = Stack_Nothing;

	return cl;	
}

class_st changeStackType(class_st cl, int type){
	
	int i;
	for(i=0 ; i < cl.stack_num ; i++){		
		if(cl.op_stack_type[i]==0){ 							// seek top of stack
			break; 
		}
	}
	
	i = i - 1;
	
	cl.op_stack_type[i] = type;
	return cl;	
}


class_st setIntegerToStack(class_st cl, int num){
	
	int i;
	for(i = 0 ; i < cl.stack_num ; i++){		
		if(cl.op_stack_type[i]==0){ 							// seek top of stack
			break; 
		}
	}
	
	if((i == cl.stack_num - 1)&&(cl.op_stack_type[i]!=0))
		return cl;// stack full
	
	cl.op_stack_type[i] = Stack_IntType;
	cl.op_stack[i] = num;
	i = i + 1;
	if(i == cl.stack_num)
		return cl;
	else 
		cl.op_stack_type[i] = Stack_Nothing;

	return cl;
}

class_st putField(class_st cl){
	char *s = getStringFromOperandStack(cl);
	if(cl.field_mem_reg == NULL){
		cl.field_mem_reg = (char *)malloc(sizeof(char)*strlen(s));
	}
	else{
		free(cl.field_mem_reg);
		cl.field_mem_reg = (char *)malloc(sizeof(char)*strlen(s));
	}
	memcpy(&cl.field_mem_reg, &s,strlen(s));
	return cl;
}

class_st getField(class_st cl){
	int i;
	for(i=0 ; i < cl.stack_num ; i++){		
		if(cl.op_stack_type[i]==0){ 							// seek top of stack
			break; 
		}
	}
	
	if((i == cl.stack_num - 1)&&(cl.op_stack_type[i]!=0))
		return cl;// stack full
	
	cl.op_stack_type[i] = Stack_Field;
	cl.op_stack[i] = 0;
	i = i + 1;
	if(i == cl.stack_num)
		return cl;
	else 
		cl.op_stack_type[i] = Stack_Nothing;
	return cl;
}


class_st decodeVM(class_st cl){
	
	int now_code = 0;
	
	while(1){
		now_code	= cl.bc_offset + cl.code_offset;
		switch(*bc_seek(now_code,1)){
			case JAVA_nop:
				now_code = now_code + 1;
				break;
			
			//case JAVA_ldc_w:
			case JAVA_ldc:
				cl = setStackFromConstantPool(cl, *bc_seek(now_code + 1,1));
				now_code = now_code + 2;
				break;
			
			case JAVA_iconst_0:
				cl = setIntegerToStack(cl,0);
				now_code = now_code + 1;
				break;
			case JAVA_iconst_1:
				cl = setIntegerToStack(cl,1);
				now_code = now_code + 1;
				break;
			case JAVA_iconst_2:
				cl = setIntegerToStack(cl,2);
				now_code = now_code + 1;
				break;
			case JAVA_iconst_3:
				cl = setIntegerToStack(cl,3);
				now_code = now_code + 1;
				break;
			case JAVA_iconst_4:
				cl = setIntegerToStack(cl,4);
				now_code = now_code + 1;
				break;
			case JAVA_iconst_5:
				cl = setIntegerToStack(cl,5);
				now_code = now_code + 1;
				break;
			
			case JAVA_iload_0:
				cl = setIntegerToStack(cl,cl.local_reg[0]);
				now_code = now_code + 1;
				break;
			case JAVA_iload_1:
				cl = setIntegerToStack(cl,cl.local_reg[1]);
				now_code = now_code + 1;
				break;
			case JAVA_iload_2:
				cl = setIntegerToStack(cl,cl.local_reg[2]);
				now_code = now_code + 1;
				break;
			case JAVA_iload_3:
				cl = setIntegerToStack(cl,cl.local_reg[3]);
				now_code = now_code + 1;
				break;			
			
			case JAVA_istore_0:
				cl.local_reg[0] = getIntegerFromOperandStack(cl);
		    now_code = now_code + 1;
				break;
			case JAVA_istore_1:
				cl.local_reg[1] = getIntegerFromOperandStack(cl);
		    now_code = now_code + 1;
				break;
			case JAVA_istore_2:
				cl.local_reg[2] = getIntegerFromOperandStack(cl);
		    now_code = now_code + 1;
				break;
			case JAVA_istore_3:
				cl.local_reg[3] = getIntegerFromOperandStack(cl);
		    now_code = now_code + 1;
				break;			
			
			case JAVA_iadd:
				now_code = now_code + 1;
				setIntegerToStack(cl,getIntegerFromOperandStack(cl) + getIntegerFromOperandStack(cl));
				break;

			case JAVA_getstatic:
				now_code = now_code + 3;
				break;
			
			case JAVA_getfield:
				now_code = now_code + 3;
				cl = getField(cl);
				break;
			case JAVA_putfield:
				now_code = now_code + 3;
				cl = putField(cl);
				break;
			
			case JAVA_i2c:
				now_code = now_code + 1;
				cl = changeStackType(cl, Stack_CharType);	
				break;
			
			case JAVA_goto:
				now_code = now_code +(int16_t)((*bc_seek(now_code + 1, 1) << 8) + *bc_seek(now_code + 2, 1));
				break;
			
			case JAVA_bipush:
				cl = setIntegerToStack(cl,*bc_seek(now_code + 1,1));
				now_code = now_code + 2;
				break;
			case JAVA_invokevirtual:
				invokevirtual_callFunction(cl,seekNameAndType_name((*bc_seek(now_code + 1, 1) << 8) + *bc_seek(now_code + 2, 1)).stack_pt);
				now_code = now_code + 3;
				break;

			case JAVA_return:
				cl.code_offset = 0;
				return cl;
			default:
				break;
			
		}
		
		cl.code_offset = now_code - cl.bc_offset;
	}
		
	return cl;
}


class_st invokevirtual_callFunction(class_st cl, char* func_name){
	
	if(strncmp(func_name,"println",7) == 0){
		char str[64]; 
		char *strn = getStringFromOperandStack(cl);
		sprintf(str,"%s",strn);
		uart_print(str);
		uart_print("\r\n");
		return cl;
	}else if(strncmp(func_name,"print",5) == 0){
		char str[64]; 
		char *strn = getStringFromOperandStack(cl);
		sprintf(str,"%s",strn);
		uart_print(str);
		return cl;
	}else if(strncmp(func_name,"read",4) == 0){
		int getInt;
		getInt = uart_read();
		cl = setIntegerToStack(cl,getInt);
		return cl;
	}
	
	return cl;
}


