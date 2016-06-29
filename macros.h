/*!
   \file macros.h
   \brief Macros utilizadas pela JVM.

   Este arquivo contém as definições das macros utilizados pela JVM e as funções
   necessárias para manipulação de access flags.
   As macros estão agrupados de acordo com sua utilização.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#ifndef MACROS_H
#define MACROS_H

#include "types.h"

/**
 * \defgroup macros_flags Access Flags
 * Macros para manipulação de acess flags
 * @{
 */

// Definição das macros de access flags do .class
#define ACC_PUBLIC 0x0001       /** Declarada pública: pode ser acessada de fora do pacote. */
#define ACC_FINAL 0x0010        /** Declarada final: não pode ter subclasses. */
#define ACC_SUPER 0x0020        /** Chama métodos de superclasse via a instrução invokespecial. */
#define ACC_INTERFACE 0x0200    /** É interface, não uma classe. */
#define ACC_ABSTRACT 0x0400     /** Declarada abstrata: não pode ser instanciada. */

// Definição das macros de access flags de fields
#define ACC_PUBLIC 0x0001       /** Declarada pública: pode ser acessada de fora do pacote. */
#define ACC_PRIVATE 0x0002      /** Declarada privada: contexto restrito à definição da classe. */
#define ACC_PROTECTED 0x0004    /** Declarada protegida: pode ser usada na classe e nas subclasses. */
#define ACC_STATIC 0x0008       /** Declarada estática: variável de classe e não de instância. */
#define ACC_FINAL 0x0010        /** Declarada final: não pode ter seu valor alterado após a iniciação. */
#define ACC_VOLATILE 0x0040     /** Declarada volátil: não pode ser colocada em cache. A Thread que a usa deve conciliar sua cópia dessa variável com a mestra toda vez que for acessá-la. */
#define ACC_TRANSIENT 0x0080    /** Declarada transiente: não pode ser lida ou gravada por um gerente de objetos persistente. (Reserva para uso futuro da Sun) */

// Definição das macros de access flags de métodos
#define ACC_PUBLIC 0x0001       /** Público: pode ser acessado de fora do pacote. */
#define ACC_PRIVATE 0x0002      /** Privado: acesso restrito à definição da classe. */
#define ACC_PROTECTED 0x0004    /** Protegido: pode ser chamado na classe e subclasses. */
#define ACC_STATIC 0x0008       /** Estático: método de classe (chamado sem referir objeto) */
#define ACC_FINAL 0x0010        /** Final: não pode ser sobre-escrito em subclasses. */
#define ACC_SYNCHRONIZED 0x0020 /** Sincronizado: requer um monitor antes de ser executado (Thread) */
#define ACC_NATIVE 0x0100       /** Nativo: implementado em linguagem não Java (C, C++, Assembly) */
#define ACC_ABSTRACT 0x0400     /** Abstrato: sem definição, deve ser sobre-escrito em uma subclasse. */
#define ACC_STRICT 0x0800       /** Strictfp: utiliza modo de ponto flutuante FP-strict (não normalizado) */

// Definição das macros de access flags de inner classes
#define ACC_PUBLIC 0x0001       /** Marcada ou implicitamente public no fonte. */
#define ACC_PRIVATE 0x0002      /** Marcada private no fonte. */
#define ACC_PROTECTED 0x0004    /** Marcada protected no fonte. */
#define ACC_STATIC 0x0008       /** Marcada ou implicitamente static no fonte. */
#define ACC_FINAL 0x0010        /** Marcada final no fonte. Não pode ser estendida. */
#define ACC_INTERFACE 0x0200    /** É uma interface no fonte. */
#define ACC_ABSTRACT 0x0400     /** Marcada abstract no fonte. Possui apenas métodos abstratos. Não pode ser instanciada. */

/** @} */ // fim da definição de macros_flags

#define CONST_VALUE "ConstantValue"         /** String que representa o atributo Constant Value. */
#define CODE "Code"                         /** String que representa o atributo Code. */
#define EXCEPTION "Exceptions"              /** String que representa o atributo Exceptions. */
#define INNER_CLASSES "InnerClasses"        /** String que representa o atributo Inner Classes. */
#define SOURCE_FILE "SourceFile"            /** String que representa o atributo Source File. */
#define LINE_NUM_TABLE "LineNumberTable"    /** String que representa o atributo Line Number Table. */

// Macros para identificar o significado do campo tag de um attribute
#define CONST_VALUE_NUM 1       /** Tag que representa o atributo Constant Value. */
#define CODE_NUM 2              /** Tag que representa o atributo Code. */
#define EXCEPTION_NUM 3         /** Tag que representa o atributo Exceptions. */
#define INNER_CLASSES_NUM 4     /** Tag que representa o atributo Inner Classes. */
#define SOURCE_FILE_NUM 5       /** Tag que representa o atributo Source File. */
#define INVALIDO_NUM 6          /** Tag que representa um atributo não suportado pela JVM. */

// Macros que definem tags para identificar os tipos dos operandos
#define TAG_UTF8 1                      /** Tag que representa um tipo UTF8. */
#define TAG_INTEGER 3                   /** Tag que representa um tipo Integer. */
#define TAG_FLOAT 4                     /** Tag que representa um tipo Float. */
#define TAG_LONG 5                      /** Tag que representa um tipo Long. */
#define TAG_DOUBLE 6                    /** Tag que representa um tipo Double. */
#define TAG_CLASS 7                     /** Tag que representa um tipo Class. */
#define TAG_STRING 8                    /** Tag que representa um tipo String. */
#define TAG_FIELD_REF 9                 /** Tag que representa um Field Ref. */
#define TAG_METHOD_REF 10               /** Tag que representa um Method Ref. */
#define TAG_INTERFACE_METHOD_REF 11     /** Tag que representa um Interface Method Ref. */
#define TAG_NAME_AND_TYPE 12            /** Tag que representa um Name and Type. */
#define TAG_METHOD_HANDLE 15            /** Tag que representa um Method Handle. */
#define TAG_METHOD_TYPE 16              /** Tag que representa um Method Type. */
#define TAG_INVOKE_DYNAMIC 18           /** Tag que representa um Invoke Dynamic. */
#define TAG_OBJECT_REF 19               /** Tag que representa um Object Ref. */
#define TAG_NULL 20                     /** Tag que representa um tipo Null. */
#define TAG_ARRAY_REF 21		/** Tag que representa um endereço de Array */


// Macros que definem os tipos de um array Java
#define BOOLEAN_ARRAY 4			/** Tipo Boolean. */
#define BYTE_ARRAY 8              	/** Tipo Byte. */
#define CHAR_ARRAY 5             	/** Tipo Char. */
#define SHORT_ARRAY 9             	/** Tipo Short. */
#define INT_ARRAY 10               	/** Tipo Int. */
#define LONG_ARRAY 11              	/** Tipo Long. */
#define FLOAT_ARRAY 6           	/** Tipo Float. */
#define DOUBLE_ARRAY 7           	/** Tipo Double. */
#define OBJETO_ARRAY 0     		/** Tipo Array de Objetos. */
#define ARRAY_ARRAY 1      		/** Tipo Array de Arrays. */


#define BOOLEAN_ARRAY 4
#define BYTE_ARRAY 8
#define CHAR_ARRAY 5
#define SHORT_ARRAY 9
#define INT_ARRAY 10
#define LONG_ARRAY 11
#define FLOAT_ARRAY 6
#define DOUBLE_ARRAY 7
#define OBJETO_ARRAY 0
#define ARRAY_ARRAY 1

 /*!
    \brief Exibe uma access flag das classes no formato "0x000 [ value ]."

    \param flag máscara da flag.

    \return Nenhum
 */
void exibir_access_flag_class(u2 flag);

 /*!
    \brief Exibe uma access flag dos fields no formato "0x000 [ value ]".

    \param flag máscada da flag.

    \return Nenhum
 */
void exibir_access_flag_field(u2 flag);

/*!
   \brief Exibe uma access flag dos métodos no formato "0x000 [ value ]".

   \param flag máscada da flag.

   \return Nenhum
*/void exibir_access_flag_method(u2 flag);

/*!
   \brief Exibe uma access flag das inner classes no formato "0x000 [ value ]".

   \param flag máscada da flag.

   \return Nenhum
*/
void exibir_access_flag_inner_class(u2 flag);

#endif /* MACROS_H */
