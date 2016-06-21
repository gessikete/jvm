#ifndef MACROS_H
#define MACROS_H

#include "types.h"

/* Definição das macros de access flags do .class */
#define ACC_PUBLIC 0x0001       // Declarada pública: pode ser acessada de fora do pacote.
#define ACC_FINAL 0x0010        // Declarada final: não pode ter subclasses
#define ACC_SUPER 0x0020        // Chama métodos de superclasse via a instrução invokespecial.
#define ACC_INTERFACE 0x0200    // É interface, não uma classe.
#define ACC_ABSTRACT 0x0400     // Declarada abstrata: não pode ser instanciada.

/* Definição das macros de access flags de fields*/
#define ACC_PUBLIC 0x0001       // Declarada pública: pode ser acessada de fora do pacote.
#define ACC_PRIVATE 0x0002      // Declarada privada: contexto restrito à definição da classe.
#define ACC_PROTECTED 0x0004    // Declarada protegida: pode ser usada na classe e nas subclasses.
#define ACC_STATIC 0x0008       // Declarada estática: variável de classe e não de instância.
#define ACC_FINAL 0x0010        // Declarada final: não pode ter seu valor alterado após a iniciação.
#define ACC_VOLATILE 0x0040     // Declarada volátil: não pode ser colocada em cache. A Thread que a usa deve conciliar sua cópia dessa variável com a mestra toda vez que for acessá-la.
#define ACC_TRANSIENT 0x0080    // Declarada transiente: não pode ser lida ou gravada por um gerente de objetos persistente. (Reserva para uso futuro da Sun)

/* Definição das macros de access flags de métodos */
#define ACC_PUBLIC 0x0001       // Público: pode ser acessado de fora do pacote.
#define ACC_PRIVATE 0x0002      // Privado: acesso restrito à definição da classe.
#define ACC_PROTECTED 0x0004    // Protegido: pode ser chamado na classe e subclasses
#define ACC_STATIC 0x0008       // Estático: método de classe (chamado sem referir objeto)
#define ACC_FINAL 0x0010        // Final: não pode ser sobre-escrito em subclasses
#define ACC_SYNCHRONIZED 0x0020 // Sincronizado: requer um monitor antes de ser executado (Thread)
#define ACC_NATIVE 0x0100       // Nativo: implementado em linguagem não Java (C, C++, Assembly)
#define ACC_ABSTRACT 0x0400     // Abstrato: sem definição, deve ser sobre-escrito em uma subclasse.
#define ACC_STRICT 0x0800       // Strictfp: utiliza modo de ponto flutuante FP-strict (não normalizado)

/* Definição das macros de access flags de inner classes */
#define ACC_PUBLIC 0x0001       // Marcada ou implicitamente public no fonte.
#define ACC_PRIVATE 0x0002      // Marcada private no fonte.
#define ACC_PROTECTED 0x0004    // Marcada protected no fonte.
#define ACC_STATIC 0x0008       // Marcada ou implicitamente static no fonte.
#define ACC_FINAL 0x0010        // Marcada final no fonte. Não pode ser estendida.
#define ACC_INTERFACE 0x0200    // É uma interface no fonte.
#define ACC_ABSTRACT 0x0400     // Marcada abstract no fonte. Possui apenas métodos abstratos. Não pode ser instanciada.

/* Fim das definições das macros de access flags */

#define CONST_VALUE "ConstantValue"
#define CODE "Code"
#define EXCEPTION "Exceptions"
#define INNER_CLASSES "InnerClasses"
#define SOURCE_FILE "SourceFile"
#define LINE_NUM_TABLE "LineNumberTable"

// Macros para identificar o significado do campo tag de um attribute
#define CONST_VALUE_NUM 1
#define CODE_NUM 2
#define EXCEPTION_NUM 3
#define INNER_CLASSES_NUM 4
#define SOURCE_FILE_NUM 5
#define INVALIDO_NUM 6

// Macros que definem tags para identificar os tipos dos operandos
#define TAG_UTF8 1
#define TAG_INTEGER 3
#define TAG_FLOAT 4
#define TAG_LONG 5
#define TAG_DOUBLE 6
#define TAG_CLASS 7
#define TAG_STRING 8
#define TAG_FIELD_REF 9
#define TAG_METHOD_REF 10
#define TAG_INTERFACE_METHOD_REF 11
#define TAG_NAME_AND_TYPE 12
#define TAG_METHOD_HANDLE 15
#define TAG_METHOD_TYPE 16
#define TAG_INVOKE_DYNAMIC 18
#define TAG_OBJECT_REF 19
#define TAG_NULL 20
/* Declaração dos métodos */
/*
 * Exibe uma access flag das classes no formato "0x000 [ value ]"
 *
 * Parâmetros:
 *       u2 flag: máscara da flag
 *
 * Retorno:
 *       Nenhum
 */
void exibir_access_flag_class(u2 flag);

/*
 * Exibe uma access flag dos fields no formato "0x000 [ value ]"
 *
 * Parâmetros:
 *       u2 flag: máscara da flag
 *
 * Retorno:
 *       Nenhum
 */
void exibir_access_flag_field(u2 flag);

/*
 * Exibe uma access flag dos métodos no formato "0x000 [ value ]"
 *
 * Parâmetros:
 *       u2 flag: máscara da flag
 *
 * Retorno:
 *       Nenhum
 */
void exibir_access_flag_method(u2 flag);

/*
 * Exibe uma access flag das inner classes no formato "0x000 [ value ]"
 *
 * Parâmetros:
 *       u2 flag: máscara da flag
 *
 * Retorno:
 *       Nenhum
 */
void exibir_access_flag_inner_class(u2 flag);

#endif /* MACROS_H */
