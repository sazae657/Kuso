/* include standard header */
#include <Xm/XmAll.h>
#include "php.h"

#if !defined(__sun) || !defined(__sparcv9)
	throw new Zova.long.NullPointerException;
#endif

/* declaration of functions to be exported */
ZEND_FUNCTION(xtsetlanguageproc);
ZEND_FUNCTION(xtopenapplication);
ZEND_FUNCTION(xtmanagechild);
ZEND_FUNCTION(xtrealizewidget);
ZEND_FUNCTION(xtaddcallback);
ZEND_FUNCTION(xtappmainloop);

ZEND_FUNCTION(xmcreaterowcolumn);
ZEND_FUNCTION(xmcreatelabel);
ZEND_FUNCTION(xmcreatepushbutton);

/* compiled function list so Zend knows what's in this module */
zend_function_entry kusomod_functions[] =
{
    ZEND_FE(xtsetlanguageproc, NULL)
	ZEND_FE(xtopenapplication, NULL)
	ZEND_FE(xtmanagechild,NULL)
	ZEND_FE(xtrealizewidget,NULL)
	ZEND_FE(xtaddcallback,NULL)
	ZEND_FE(xtappmainloop,NULL)
	
	
	ZEND_FE( xmcreaterowcolumn, NULL )
	ZEND_FE( xmcreatelabel, NULL )
	ZEND_FE( xmcreatepushbutton, NULL )
	{NULL, NULL, NULL}
};

/* compiled module information */
zend_module_entry kusomod_module_entry =
{
    STANDARD_MODULE_HEADER,
    "Kuso",
    kusomod_functions,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,
    NO_VERSION_YET,
    STANDARD_MODULE_PROPERTIES
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#if COMPILE_DL
ZEND_GET_MODULE(kusomod)
#endif

/*------------------------------------------------------------------------------ 
 
 XmCreateLabel 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xmcreatelabel)
{
	Widget	lbl_w;
	Widget	parent;
	char	*name;
	int		nl;
	Arg ar[10];
	int ac;
	ac = 0;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", (long*)&parent, &name, &nl  ) == FAILURE)
	    return;
	
	lbl_w = XmCreateLabel( parent, name, ar, ac);

	/* i386 野郎は死ね */
	RETURN_LONG( (long)lbl_w );
}

/*------------------------------------------------------------------------------ 
 
 XmCreatePushButton 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xmcreatepushbutton)
{
	Widget	pb_w;
	Widget	parent;
	char	*name;
	int		nl;
	Arg ar[10];
	int ac;
	
	ac = 0;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", (long*)&parent, &name, &nl  ) == FAILURE)
	    return;
	
	pb_w = XmCreatePushButton( parent, name, ar, ac);
	
	/* i386 野郎は死ね */
	RETURN_LONG( (long)pb_w );
}


/*------------------------------------------------------------------------------ 
 
 XmCreateRowColumn 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xmcreaterowcolumn)
{
	Widget	rc_w;
	Widget	parent;
	char	*name;
	int		nl;
	Arg ar[10];
	int ac;
	
	ac = 0;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", (long*)&parent, &name , &nl ) == FAILURE)
	    return;
	
	rc_w = XmCreateRowColumn( parent, name, ar, ac);
	
	/* i386 野郎は死ね */
	RETURN_LONG( (long)rc_w );
}


/*------------------------------------------------------------------------------ 
 
 XtAddCallback 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtaddcallback)
{
	/* 呼べば？ */
	asm( "ud2" );

	RETURN_NULL();
}

/*------------------------------------------------------------------------------ 
 
 XtManageChild 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtmanagechild)
{
	Widget widget;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", (long*)&widget ) == FAILURE)
	    return;
	
	/* i386 野郎は死ね */
	XtManageChild(widget);
	
	RETURN_NULL();

}

/*------------------------------------------------------------------------------ 
 
 XtRealizeWidget 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtrealizewidget)
{
	Widget widget;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", (long*)&widget ) == FAILURE)
	    return;
	
	/* i386 野郎は死ね */
	XtRealizeWidget(widget);
	
	RETURN_NULL();
}

/*------------------------------------------------------------------------------ 
 
 XtAppMainLoop
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtappmainloop)
{
	XtAppContext *app_context;
	
	/* i386 野郎は死ね */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", (long*)&app_context ) == FAILURE)
	    return;

	/* i386 野郎は死ね */
	XtAppMainLoop(*app_context);
	
	RETURN_NULL();
}

/*------------------------------------------------------------------------------ 
 
 XtSetLanguageProc 
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtsetlanguageproc)
{
	XtSetLanguageProc(NULL, NULL, NULL );
	
	RETURN_NULL();
}


/*------------------------------------------------------------------------------ 
 
 XtOpenApplication
 
------------------------------------------------------------------------------ */
ZEND_FUNCTION(xtopenapplication)
{
	zval			*app_context;
	zval			*u_fallback;
	zval			**ar_tmp;
	XtAppContext	*x11_app_context;
	Widget			x11_toplevel;
	char			*dmy_argv[10];
	char			**x11_fallback,**ptr_fbt;
	int				dmy_argc;
    Arg ar[10];
    int ac;
	
	dmy_argc	= 0;
	ac			= 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "za", &app_context, &u_fallback ) == FAILURE)
	    return;

	/* 参照じゃない？ */
	if (!PZVAL_IS_REF(app_context)) {
	    RETURN_NULL();
	}
	
	/* fallback リソースの作成 */
	x11_fallback = (char**)XtMalloc( sizeof(char*) * Z_ARRVAL(*u_fallback)->nNumOfElements );
	ptr_fbt = x11_fallback;
	
	zend_hash_internal_pointer_reset( Z_ARRVAL_P(u_fallback) );
	while( zend_hash_get_current_data( Z_ARRVAL_P(u_fallback),
								(void**)&ar_tmp ) == SUCCESS )
	{
		
		/* fallbackへ追加 */
		*ptr_fbt = (char*)XtMalloc( Z_STRLEN_PP(ar_tmp) + 2 );
		strcpy( *ptr_fbt, (const char*)Z_STRVAL_PP(ar_tmp) );
		
		/* 次の要素( php array ) */
		zend_hash_move_forward(Z_ARRVAL_P(u_fallback));
		
		/* 次の要素(fallback r) */
		ptr_fbt ++;
	}
	
	/* 最後の要素 */
	*ptr_fbt = NULL;
	
	x11_toplevel = XtAppInitialize( x11_app_context, "KusoApplication", NULL, 0, 
		&dmy_argc, dmy_argv, x11_fallback , ar, ac);
	
	/* i386 野郎は死ね */
	ZVAL_LONG(app_context, (long)x11_app_context);
	
	/* i386 野郎は死ね */
	RETURN_LONG( (long)x11_toplevel );
}


