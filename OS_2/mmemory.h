#ifdef MMEMORY_EXPORTS
#define MMEMORY_API __declspec(dllexport) 
#else
#define MMEMORY_API __declspec(dllimport) 
#endif

#include <stddef.h>

typedef char* Address;				// Тип описывающий адрес блока 

/**
		@func	_malloc
		@brief	Выделяет блок памяти определенного размера

	@param	[out] ptr		адресс блока
	@param	[in]  szBlock	размер блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	нехватка памяти
	@retval	1	неизвестная ошибка
	**/
MMEMORY_API int _malloc(Address* ptr, size_t szBlock);



/**
		@func	_free
		@brief	Удаление блока памяти

	@param	[in] ptr		адресс блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	1	неизвестная ошибка
	**/
MMEMORY_API int _free(Address ptr);



/**
		@func	_read
		@brief	Чтение информации из блока памяти

	@param	[in] ptr		адресс блока
	@param	[in] pBuffer	адресс буфера куда копируется инфомация
	@param	[in] szBuffer	размер буфера

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	доступ за пределы блока
	@retval	1	неизвестная ошибка
	**/
MMEMORY_API int _readData(Address ptr, void* pBuffer, size_t szBuffer);



/**
		@func	_write
		@brief	Запись информации в блок памяти

	@param	[in] ptr		адресс блока
	@param	[in] pBuffer	адресс буфера куда копируется инфомация
	@param	[in] szBuffer	размер буфера

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	доступ за пределы блока
	@retval	1	неизвестная ошибка
	**/
MMEMORY_API int _writeData(Address ptr, void* pBuffer, size_t szBuffer);



/**
		@func	_init
		@brief	Инициализация модели менеджера памяти

	@param	[in] n		количество страниц
	@param	[in] szPage	размер страницы

	В варианте 1 и 2 общий объем памяти расчитывается как n*szPage

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	1	неизвестная ошибка
	**/
MMEMORY_API int _init(int n, int szPage);

MMEMORY_API void _printBuffer(Address ptr, size_t size);