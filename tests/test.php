<?
	dl('kuso.so');
	print_r (get_extension_funcs ("Kuso"));
	print ( "----- begin ------\n" );

	$fallback[0] = "*fontList:         *-fixed-medium-r-normal--16-*-*-*-*-*-*-*:";
	$fallback[1] = "*title:            Hello PHP Extention";
	$fallback[2] = "*label.labelString: Êµ";
	$fallback[3] = "*button.labelString: ¤¦¤ó¤³";


	XtSetLanguageProc();
	$toplevel = XtOpenApplication( &$app_context, $fallback );
	
	$back = XmCreateRowColumn( $toplevel, "back" );
	XtManageChild( $back );
	
	$ctrl = XmCreateRowColumn( $back, "ctrl" );
	XtManageChild( $ctrl );
	
	$label = XmCreateLabel( $ctrl, "label" );
	XtManageChild( $label );


	$button = XmCreatePushButton( $back,"button" );
	XtManageChild( $button );
	
	XtRealizeWidget($toplevel);
	XtAppMainLoop($app_context);
?>


