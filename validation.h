#include <stdbool.h>
#include <stdio.h>
#include "types.h"

/*
 * Valida o número mágico
 *
 * Parâmetros:
 *       u4 magic: valor do magic number
 *
 * Retorno:
 *       bool: falso, no caso de magic number inválido
 *			   true, no caso de magic number válido
 */
bool validar_magic(u4 magic);

/*
 * Valida as versões minor e major
 * For k ≥ 2, JDK release 1.k supports class file format versions in
 * the range 45.0 through 44+k.0 inclusive
 *
 * Parâmetros:
 *       u2 minor: minor version number
 *		 u2 major: major version number
 *
 * Retorno:
 *       bool: falso, no caso de versão inválida
 *			   true, no caso de versão válida
 */
bool validar_version(u2 minor, u2 major);


/*
 * Verifica se a tag lida é válida.
 *
 * Parâmetros:
 *       u2 tag: tag a ser verificada
 *
 * Retorno:
 *       bool: falso, caso tag seja inválida, ou true, caso seja válida
 */
bool validar_tag(u2 tag);
