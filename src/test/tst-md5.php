<?php
/**
 * md5 test program. <br />
 *
 * @author adan-shaw <adan_shaw@qq.com>
 */
$_str = array("", "a", "abc", "message digest", 
	"123456", "153759", "619315", "abcdefghijklmnopqrstuvwxyz");

foreach ( $_str as $_val )
{
    //echo "md5(\"".$_val."\")=" . md5( $_val )."\n";
    printf("md5(\"%-26s\")=%s\n", $_val, md5($_val));
}
?>
