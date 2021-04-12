<?php
error_reporting(E_ALL);



$uapp = "./piiotest writepin ";

$cmd = $uapp . $_POST["pinno"] . " " . $_POST["pinval"]. '';

echo "User Test App". $cmd;

$output = shell_exec($cmd);
echo "<pre>$output</pre>";


?>
<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">

    GPIO Number:
    <input type="text" name="pinno" /> <br>
    Value - 0 or 1 :
    <input type="text" name="pinval" /> <br>
    <input type="submit" name="btnSendForm" value="Execute" />
</form>

<?php


	
?>

