namespace cpp save_service
service save {
    i32 save_data(1: string username, 2: string passwd, 3: i32 player1_id, 4: i32 player2_id);
}