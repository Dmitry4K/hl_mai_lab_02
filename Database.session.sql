alter table UserToChat
add constraint forgein key user_id references User (id)