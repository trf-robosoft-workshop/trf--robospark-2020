<?php
$con=mysqli_connect('localhost','root',"",'stud_data');
if(!$con)
{
    echo "Connection Error ".mysqli_connect_error();
}
else{
    echo "<h3>Database connection successful</h3>";
}
?>