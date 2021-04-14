<?php
    error_reporting(E_ALL);

    $uapp = "ls -al";
    $cmd = $uapp;

    echo "User Test App". $cmd;

    $output = shell_exec($cmd);
    echo "<pre>$output</pre>";

?>

<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="get">
    display_machines();
</form>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    Add Machine:
    <input type="submit" class="button" name="Add Machine" value="addm" />
    Machine Number:
    <input type="number" name="Machine Name" id="mnum" min="1" max="5"/> <br>
    <input type="submit" name="btnSendForm" value="Delete Machine" />
    <input type="submit" name="btnSendForm" value="Update Machine" />
</form>